//
// Created by Manuel Hahn on 5/27/22.
//

#include <iostream>
#include "Converter.h"

static void printFromInt(int);
static void printFromFloat(float);
static void printFromChar(char);
static void printFromDouble(double);
static void printChar(const char &);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Wrong argument count!" << std::endl;
        return EXIT_FAILURE;
    }
    Converter c;
    Converter::TYPE type = c.getType(argv[1]);
    if (c.hadError()) {
        std::cerr << "Value out of range!" << std::endl;
        return EXIT_FAILURE;
    }
    switch (type) {
        case Converter::INT:    printFromInt(c.convertToInt(argv[1]));       break;
        case Converter::CHAR:   printFromChar(c.convertToChar(argv[1]));     break;
        case Converter::FLOAT:  printFromFloat(c.convertToFloat(argv[1]));   break;
        case Converter::DOUBLE: printFromDouble(c.convertToDouble(argv[1])); break;
        default:
            std::cerr << "\"" << argv[1] << "\" could not be converted!" << std::endl;
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static void printFromInt(int arg) {
    if (arg >= CHAR_MIN && arg <= CHAR_MAX) {
        printChar(static_cast<char>(arg));
    } else {
        std::cout << "char:   impossible" << std::endl;
    }
    std::cout << "int:    " << arg << std::endl
              << "float:  " << std::fixed << static_cast<float>(arg) << std::endl
              << "double: " << std::fixed << static_cast<double>(arg) << std::endl;
}

static void printFromChar(char arg) {
    printChar(arg);
    std::cout << "int:    " << static_cast<int>(arg) << std::endl
              << "float:  " << std::fixed << static_cast<float>(arg) << std::endl
              << "double: " << std::fixed << static_cast<double>(arg) << std::endl;
}

static void printFromFloat(float arg) {
    if (arg >= CHAR_MIN && arg <= CHAR_MAX) {
        printChar(static_cast<char>(arg));
    } else {
        std::cout << "char:   impossible" << std::endl;
    }
    if (!isnan(arg) && !isinf(arg)) {
        std::cout << "int:    " << static_cast<int>(arg) << std::endl;
    } else {
        std::cout << "int:    impossible" << std::endl;
    }
    std::cout << "float:  " << std::fixed << arg << std::endl
              << "double: " << std::fixed << static_cast<double>(arg) << std::endl;
}

static void printFromDouble(double arg) {
    if (arg >= CHAR_MIN && arg <= CHAR_MAX) {
        printChar(static_cast<char>(arg));
    } else {
        std::cout << "char:   impossible" << std::endl;
    }
    if (!isnan(arg) && !isinf(arg)) {
        std::cout << "int:    " << static_cast<int>(arg) << std::endl;
    } else {
        std::cout << "int:    impossible" << std::endl;
    }
    std::cout << "float:  " << std::fixed << static_cast<float>(arg) << std::endl
              << "double: " << std::fixed << arg  << std::endl;
}

static void printChar(const char &arg) {
    if (isprint(arg)) {
        std::cout << "char:   '" << arg << "'" << std::endl;
    } else {
        std::cout << "char:   not displayable" << std::endl;
    }
}
