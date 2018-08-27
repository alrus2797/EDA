#ifndef PPILA_H
#define PPILA_H

#include "PStructure.h"

class PPila : public PStructure
{
    
public:
    PPila(){}
    int pop()
    {
        PNodo* temp= this->first;
        while(temp->siguiente!= this->last){
            temp=temp->siguiente;
        }
        int res=temp->siguiente->value;

        temp->siguiente=0;
        this->last=temp;
        cout<<endl<<"Dato Borrado: "<<res<<endl;
        return res;

    }
    ~PPila(){}
};


#endif