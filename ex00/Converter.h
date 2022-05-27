//
// Created by Manuel Hahn on 5/27/22.
//

#ifndef EX00_CONVERTER_H
#define EX00_CONVERTER_H


#include <string>

class Converter {
public:
    enum TYPE {
        INT, FLOAT, DOUBLE, CHAR, ERROR
    };

    Converter();
    Converter(const Converter &);
    ~Converter();

    TYPE getType(const std::string &);
    int convertToInt(const std::string &);
    float convertToFloat(const std::string &);
    double convertToDouble(const std::string &);
    char convertToChar(const std::string &);
    bool hadError() const;

    Converter & operator=(const Converter &);

private:
    bool checkFloat(const std::string &);
    bool checkDouble(const std::string &);
    bool checkInt(const std::string &);

    bool error;
};


#endif //EX00_CONVERTER_H
