//
// Created by Manuel Hahn on 5/27/22.
//

#include <cstdlib>
#include <iostream>
#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

Base* generate() {
    switch (arc4random() % 3) {
        case 1: return new A();
        case 2: return new B();
        default: return new C();
    }
}

void identify(Base* self) {
    if (dynamic_cast<A *>(self) != 0L) {
        std::cout << "Type is A" << std::endl;
    } else if (dynamic_cast<B *>(self) != 0L) {
        std::cout << "Type is B" << std::endl;
    } else if (dynamic_cast<C *>(self) != 0L) {
        std::cout << "Type is C" << std::endl;
    } else {
        std::cout << "Reference given is not a subclass of Base!" << std::endl;
    }
}

void identify(Base& self) {
    try {
        (void) dynamic_cast<A &>(self);
        std::cout << "Type is A" << std::endl;
        return;
    } catch (std::bad_cast &ex) {}
    try {
        (void) dynamic_cast<B &>(self);
        std::cout << "Type is B" << std::endl;
        return;
    } catch (std::bad_cast & ex) {}
    try {
        (void) dynamic_cast<C &>(self);
        std::cout << "Type is C" << std::endl;
        return;
    } catch (std::bad_cast &ex) {}
    std::cout << "Not a reference to a subclass of Base!" <<std::endl;
}
