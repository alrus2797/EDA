#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;


class Nodo
{
public:
    /* data */
    Nodo* izq;
    Nodo* der;
public:
    Nodo();
    virtual int getValue() = 0;
    virtual void getRawValue() = 0;
    ~Nodo();


};

Nodo::Nodo()
{
    this->der = 0;
    this->izq = 0;
}

Nodo::~Nodo()
{
}


#endif