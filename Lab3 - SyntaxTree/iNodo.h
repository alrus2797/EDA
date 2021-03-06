#ifndef INODO_H
#define INODO_H

#include "Nodo.h"


class iNodo : public Nodo
{
private:
    int value;
public:
    iNodo(int value);
    int getValue() override;
    void getRawValue() override;
    string getStrValue() override;
    ~iNodo();

friend class Arbol;
};


iNodo::iNodo(int value)
{
    this->value = value;
}

int iNodo::getValue(){
    return this->value;
}

void iNodo::getRawValue(){
    cout<<this->value;
}

string iNodo::getStrValue(){
    return to_string(this->value);
}

iNodo::~iNodo()
{
}


#endif