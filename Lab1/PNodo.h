#ifndef PNODO_H
#define PNODO_H

#include <iostream>

using namespace std;


class PNodo
{
private:
    int value;
    PNodo* siguiente;
public:
    PNodo(int );
    ~PNodo();

friend class PStructure;
friend class PCola;
friend class PPila;
};

PNodo::PNodo(int v)
{
    this->value=v;
    this->siguiente=0;
}

PNodo::~PNodo()
{
}

#endif