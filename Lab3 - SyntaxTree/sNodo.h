#ifndef SNODO_H
#define SNODO_H

#include "Nodo.h"


class sNodo : public Nodo
{
private:
    string value;
public:
    sNodo(string value);
    int getValue() override;
    void getRawValue() override;
    ~sNodo();
friend class Arbol;
};

sNodo::sNodo(string value)
{
    this->value = value;
}

int sNodo::getValue(){
    
    if (this->value == "+"){
        return this->izq->getValue() + this->der->getValue();
    }
    else if (this->value == "-"){
        return this->izq->getValue() - this->der->getValue();
    }
    else if (this->value == "*"){
        return this->izq->getValue() * this->der->getValue();
    }
}

void sNodo::getRawValue(){
    cout<<this->value;
}

sNodo::~sNodo()
{
}

#endif