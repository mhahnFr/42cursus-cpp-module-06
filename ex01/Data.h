//
// Created by Manuel Hahn on 5/27/22.
//

#ifndef EX01_DATA_H
#define EX01_DATA_H


#include <string>

class Data {
public:
    Data();
    Data(const Data &);
    ~Data();

    const std::string &getContent() const;
    void setContent(const std::string &content);

    Data & operator=(const Data &);

private:
    std::string content;
};

uintptr_t serialize(Data *);
Data *deserialize(uintptr_t);

#endif //EX01_DATA_H
