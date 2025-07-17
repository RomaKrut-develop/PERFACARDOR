// Этот файл выступает в роли основного файла interpreter.cpp. 
// Он инициализирует основной класс Interpreter а также все необохимые компоненты в private и public, которые в свою очередь будут обрабатываться в interpreter.cpp
// Приватные методы здесь выступают как капот под капотом.

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <fstream> // Работа с файлами
#include <sstream>
#include <map> // Контейнеры 
#include <vector> // Контейнеры 
#include <string> // Строковвые операции
#include <cctype> // Потоковые
#include <stdexcept> // Обработка исключений

class Interpreter { // Основной класс интерпретатора 
private: 
    std::map<std::string, int> variables;
    bool inProgram = false;

    void executeLine(const std::string& line);
    std::string trim(const std::string& s);
    std::vector<std::string> tokenize(const std::string& line);
    int evaluateExpression(const std::string& expr);

public:
    void run(const std::string& filename);
};

#endif