//
// Created by Manuel Hahn on 5/27/22.
//

#include <cerrno>
#include <climits>
#include "Converter.h"

Converter::Converter(): error(false) {}

Converter::Converter(const Converter &other): error(other.hadError()) {}

Converter::~Converter() {}

Converter &Converter::operator=(const Converter &other) {
    error = other.hadError();
    return *this;
}

Converter::TYPE Converter::getType(const std::string &string) {
    if (string.empty()) return ERROR;
    if (checkInt(string)) return INT;
    if (checkFloat(string) && (string[string.size() - 1] == 'f' || string[string.size() - 1] == 'F')) return FLOAT;
    if (checkDouble(string)) return DOUBLE;
    if (string.size() == 1) return CHAR;
    return ERROR;
}

bool Converter::hadError() const {
    return error;
}

int Converter::convertToInt(const std::string &string) {
    return static_cast<int>(strtol(string.c_str(), 0L, 10));
}

float Converter::convertToFloat(const std::string &string) {
    return strtof(string.c_str(), 0L);
}

double Converter::convertToDouble(const std::string &string) {
    return strtod(string.c_str(), 0L);
}

char Converter::convertToChar(const std::string &string) {
    return string[0];
}

bool Converter::checkFloat(const std::string &string) {
    char* end;
    strtof(string.c_str(), &end);
    error = errno == ERANGE;
    return *end != '\0';
}

bool Converter::checkInt(const std::string &string) {
    char* end;
    long res = strtol(string.c_str(), &end, 10);
    error = res < INT_MIN || res > INT_MAX || errno == ERANGE;
    return (*end == '\0');
}

bool Converter::checkDouble(const std::string &string) {
    char* end;
    strtod(string.c_str(), &end);
    error = errno == ERANGE;
    return *end == '\0';
}
