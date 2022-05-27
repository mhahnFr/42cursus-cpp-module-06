//
// Created by Manuel Hahn on 5/27/22.
//

#include "Base.h"

#define COUNT 4

int main() {
    Base* instances[COUNT];
    int i;
    for (i = 0; i < COUNT; ++i) {
        instances[i] = generate();
    }
    for (i = 0; i < COUNT; ++i) {
        identify(instances[i]);
    }
    for (i = 0; i < COUNT; ++i) {
        identify(*instances[i]);
    }
    while (i --> 0) {
        delete instances[i];
    }
}
