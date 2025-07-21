// New main.cpp (for CLI usage)
#include "Interpreter.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: interpreter <filename>\n";
        return 1;
    }

    Interpreter interpreter;
    interpreter.run(argv[1]);

    return 0;
}