//
// Created by Manuel Hahn on 5/27/22.
//

#include <iostream>
#include "Data.h"

int main() {
    Data d;

    d.setContent("Hello!");
    std::cout << "Address of the data block: " << &d << std::endl;
    std::cout << "Content: " << d.getContent() << std::endl << std::endl;
    uintptr_t raw = serialize(&d);
    std::cout << "Value of the raw pointer:  " << raw << std::endl;
    Data* dataPtr = deserialize(raw);
    std::cout << "Address of the new block:  " << dataPtr << std::endl;
    std::cout << "Content: " << dataPtr->getContent() << std::endl;
}
