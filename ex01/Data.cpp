//
// Created by Manuel Hahn on 5/27/22.
//

#include "Data.h"

const std::string &Data::getContent() const {
    return content;
}

void Data::setContent(const std::string &content) {
    Data::content = content;
}

Data::Data(): content() {}

Data::Data(const Data &other): content(other.getContent()) {}

Data::~Data() {}

Data &Data::operator=(const Data &other) {
    content = other.getContent();
    return *this;
}

uintptr_t serialize(Data* data) {
    return reinterpret_cast<uintptr_t>(data);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
