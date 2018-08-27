#ifndef PCOLA_H
#define PCOLA_H


#include "PStructure.h"


class PCola : public PStructure
{
public:
    PCola(){}
    int pop()
    {
        PNodo* temp=this->first;
        PStructure::remove(0);
        return temp->value;
    }

    ~PCola(){}
};

#endif