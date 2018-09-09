#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

// Append int to string
string operator+(const string& a, const int& b) { //outside the class
    return a + to_string(b);
}

class Nodo
{
public:
    /* data */
    Nodo* izq;
    Nodo* der;
    int id;
public:
    Nodo();
    virtual int getValue() = 0;
    virtual void getRawValue() = 0;
    virtual string getStrValue() = 0;
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