#include "Interpreter.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <fstream>
#include <stdexcept>

// Убирает лишние пробелы по краям
std::string Interpreter::trim(const std::string& s) {
    size_t first = s.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = s.find_last_not_of(" \t");
    return s.substr(first, last - first + 1);
}

// Разбирает выражение вида "1+2", "5*3", "10/2", "7-4"
int Interpreter::evaluateExpression(const std::string& expr) {
    std::istringstream iss(expr);
    int a, b;
    char op;
    if (!(iss >> a >> op >> b)) {
        throw std::runtime_error("CALC: incorrect operation: " + expr);
    }

    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("CALC: division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("CALC: operation '" + std::string(1, op) + "' is not supported");
    }
}

// Сравнивает значения по оператору
bool Interpreter::evaluateCondition(int a, int b, const std::string& op) {
    if (op == "==") return a == b;
    if (op == "!=") return a != b;
    if (op == ">")  return a > b;
    if (op == "<")  return a < b;
    if (op == ">=") return a >= b;
    if (op == "<=") return a <= b;
    throw std::runtime_error("IF: unsupported operator '" + op + "'");
}

// Выполняет одну строку программы
void Interpreter::executeLine(const std::string& line) {
    std::string trimmed = trim(line);
    if (trimmed.empty()) return;

    if (!inProgram && trimmed != "START") {
        throw std::runtime_error("Error: missing 'START' in beginning");
    }

    if (trimmed == "START") {
        if (inProgram)
            throw std::runtime_error("Error: START already defined");
        inProgram = true;
    }
    else if (trimmed == "END") {
        inProgram = false;
    }
    else if (!inProgram) {
        throw std::runtime_error("Error: command out of 'START...END' range");
    }

    else if (trimmed.substr(0, 5) == "SHOW(") {
        if (!conditionMet) return;

        std::string content = trim(trimmed.substr(5, trimmed.size() - 6));
        if (content.front() == '\'' && content.back() == '\'') {
            std::cout << content.substr(1, content.size() - 2) << std::endl;
        }
        else {
            auto it = variables.find(content);
            if (it == variables.end()) {
                throw std::runtime_error("SHOW: variable '" + content + "' is not defined");
            }
            std::cout << it->second << std::endl;
        }
    }

    else if (trimmed.substr(0, 4) == "VAR ") {
        size_t equalsPos = trimmed.find(" = ");
        if (equalsPos == std::string::npos) {
            throw std::runtime_error("VAR: missing ' = ' in declaration");
        }

        std::string varName = trim(trimmed.substr(4, equalsPos - 4));
        std::string valueStr = trim(trimmed.substr(equalsPos + 3));

        if (varName.empty()) {
            throw std::runtime_error("VAR: variable name not given");
        }

        if (variables.find(varName) != variables.end()) {
            throw std::runtime_error("VAR: variable '" + varName + "' already defined");
        }

        int value = 0;

        if (isdigit(valueStr[0]) || (valueStr.size() > 1 && valueStr[0] == '-' && isdigit(valueStr[1]))) {
            try {
                value = std::stoi(valueStr);
            } catch (...) {
                throw std::runtime_error("VAR: invalid number: " + valueStr);
            }
        } else {
            auto it = variables.find(valueStr);
            if (it == variables.end()) {
                throw std::runtime_error("VAR: variable '" + valueStr + "' not defined");
            }
            value = it->second;
        }

        variables[varName] = value;
    }

    else if (trimmed.substr(0, 5) == "CALC(") {
        if (!conditionMet) return;

        std::string body = trim(trimmed.substr(5, trimmed.size() - 6));

        size_t assignPos = body.find('=');
        if (assignPos != std::string::npos) {
            std::string varName = trim(body.substr(0, assignPos));
            std::string expr = trim(body.substr(assignPos + 1));

            if (variables.find(varName) == variables.end()) {
                throw std::runtime_error("CALC: variable '" + varName + "' not defined");
            }

            int result = evaluateExpression(expr);
            variables[varName] = result;
        }
        else {
            int result = evaluateExpression(body);
            std::cout << result << std::endl;
        }
    }

    else if (trimmed.substr(0, 3) == "IF ") {
        size_t thenPos = trimmed.find(" THEN");
        if (thenPos == std::string::npos) {
            throw std::runtime_error("IF: missing 'THEN'");
        }

        std::string condition = trim(trimmed.substr(3, thenPos - 3));
        std::istringstream iss(condition);
        std::string var1, op, var2;

        if (!(iss >> var1 >> op >> var2)) {
            throw std::runtime_error("IF: incorrect condition");
        }

        int val1 = 0, val2 = 0;

        if (variables.find(var1) != variables.end()) {
            val1 = variables[var1];
        } else if (std::isdigit(var1[0]) || (var1.size() > 1 && var1[0] == '-' && std::isdigit(var1[1]))) {
            val1 = std::stoi(var1);
        } else {
            throw std::runtime_error("IF: variable '" + var1 + "' not defined");
        }

        if (variables.find(var2) != variables.end()) {
            val2 = variables[var2];
        } else if (std::isdigit(var2[0]) || (var2.size() > 1 && var2[0] == '-' && std::isdigit(var2[1]))) {
            val2 = std::stoi(var2);
        } else {
            throw std::runtime_error("IF: variable '" + var2 + "' not defined");
        }

        conditionMet = evaluateCondition(val1, val2, op);
        inIfBlock = true;
        executeElse = false;
    }

    else if (trimmed == "ELSE") {
        if (!inIfBlock) {
            throw std::runtime_error("ELSE: no matching IF");
        }
        conditionMet = !conditionMet;
        executeElse = true;
    }

    else if (trimmed == "ENDIF") {
        inIfBlock = false;
        conditionMet = true;
        executeElse = false;
    }

    else {
        throw std::runtime_error("Unknown method or command: " + trimmed);
    }
}

// Запуск интерпретатора из файла
void Interpreter::run(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: cannot find '" << filename << "'" << std::endl;
        return;
    }

    variables.clear();
    inProgram = false;
    inIfBlock = false;
    conditionMet = true;

    std::string line;
    while (std::getline(file, line)) {
        try {
            executeLine(line);
        }
        catch (const std::exception& e) {
            std::cerr << "Error on line: " << line << "\n" << e.what() << std::endl;
            return;
        }
    }

    if (inProgram) {
        std::cerr << "Error: missing 'END'" << std::endl;
    }
}