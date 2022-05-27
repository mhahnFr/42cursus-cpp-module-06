//
// Created by Manuel Hahn on 5/27/22.
//

#ifndef EX02_BASE_H
#define EX02_BASE_H


class Base {
public:
    virtual ~Base() {};
};

Base* generate();
void identify(Base *);
void identify(Base &);


#endif //EX02_BASE_H
