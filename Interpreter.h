// Этот файл выступает в роли основного файла interpreter.cpp. 
// Он инициализирует основной класс Interpreter а также все необохимые компоненты в private и public, которые в свою очередь будут обрабатываться в interpreter.cpp
// Приватные методы здесь выступают как капот под капотом.

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <map>
#include <string>

class Interpreter {
private:
    std::map<std::string, int> variables;
    bool inProgram = false;

    // Условные блоки
    bool inIfBlock = false;
    bool executeElse = false;
    bool conditionMet = true;

    // Убирает лишние пробелы
    std::string trim(const std::string& s);

    // Вычисляет выражение
    int evaluateExpression(const std::string& expr);

    // Сравнивает значения по оператору
    bool evaluateCondition(int a, int b, const std::string& op);

    // Выполняет одну строку
    void executeLine(const std::string& line);

public:
    // Запуск интерпретатора из файла
    void run(const std::string& filename);
};

#endif // INTERPRETER_H