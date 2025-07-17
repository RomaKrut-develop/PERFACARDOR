#include "Interpreter.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <stdexcept>

// Убирает лишние пробелы по краям
std::string Interpreter::trim(const std::string& s) {
    size_t first = s.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = s.find_last_not_of(" \t");
    return s.substr(first, last - first + 1);
}

// Разбирает выражение на деление, умножение, вычитание, сложение
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
    else if (trimmed.substr(0, 11) == "CREATE VAR ") {
        std::string varName = trim(trimmed.substr(11));
        if (varName.empty()) {
            throw std::runtime_error("CREATE VAR: name don't given");
        }
        if (variables.find(varName) != variables.end()) {
            throw std::runtime_error("CREATE VAR: variable '" + varName + "' already defined");
        }
        variables[varName] = 0;
    }
    else if (trimmed.substr(0, 5) == "CALC(") {
        std::string body = trim(trimmed.substr(5, trimmed.size() - 6));

        size_t assignPos = body.find('=');
        if (assignPos != std::string::npos) {
            // Режим присваивания: VAR=1+1
            std::string varName = trim(body.substr(0, assignPos));
            std::string expr = trim(body.substr(assignPos + 1));

            if (variables.find(varName) == variables.end()) {
                throw std::runtime_error("CALC: variable '" + varName + "' not defined");
            }

            int result = evaluateExpression(expr);
            variables[varName] = result;
        }
        else {
            // Режим только вычисления: 1+1
            int result = evaluateExpression(body);
            std::cout << result << std::endl;
        }
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