#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <string>
#include <limits>
#include <windows.h>
#include <locale>
#include "Interpreter.h" // Импортируем необходимые библиотеки 

// Очистка буфера ввода
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() { // Основная функция меню (Меню в роле посредника интерпритатора и загрузчика программ )
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); // Для корректной работы киррилицы
    std::setlocale(LC_ALL, "Russian"); // Выставляем русский язык (КОТОРОГО ПОКА НЕТ)

    std::wcout << L"\n------------PERFACARDOR 1.1------------\n";
    while (true) { // Основной цикл меню
        std::wcout << L"\n------MAIN MENU------:\n";
        std::wcout << L"\nInput command:\n";
        std::wcout << L"1. Load and run\n";
        std::wcout << L"2. Help\n";
        std::wcout << L"3. Exit\n";

        int choice;
        std::wcout << L"Enter option: ";
        std::cin >> choice;

        if (std::cin.fail()) { // Ошибка меню при неверном вводе выбора
            clearInput();
            std::wcout << L"Wrong input. Choice from 1 to 3.\n";
            continue;
        }

        if (choice == 1) {
            std::string filename;
            std::wcout << L"Enter file name to load and run: \n";
            clearInput(); // Очистка буфера перед строковым вводом
            std::getline(std::cin, filename);

            std::string fullpath = "tray/" + filename;

            Interpreter interpreter;
            std::wcout << L" \n";
            interpreter.run(fullpath);
        }
        else if (choice == 2) {
            std::wcout << L"\n------PROGRAM HELP------:\n";
            std::wcout << L"\nTo prepare your .txt program for load, put it in 'tray' folder.\n";
            std::wcout << L"\nTo run program, enter '1' at the main menu. Following this, specify the file name for execution. The program will load and run itself..\n";
            std::wcout << L"\nFor more, read 'GUIDE.md'\n";
        }
        else if (choice == 3) {
            std::wcout << L"Closing.\n";
            break;
        }
        else {
            std::wcout << L"Incorrect input. Try again.\n";
        }
    }

    return 0; // Закрытие
}