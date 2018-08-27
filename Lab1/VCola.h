#ifndef VCOLA_H
#define VCOLA_H

#include "VStructure.h"

template<int N>

class VCola : public VStructure<N>
{
private:
public:
    VCola(){
    }

    int pop()
    {
        if (this->actual==0)
            return -1;

        int res= this->array[0];        
        for(int i = 1; i < this->actual ; i++){
            this->array[i-1]=this->array[i];
        }

        this->array[this->actual-1]=0;
        this->actual--;
        return res;
    }

    ~VCola(){

    }
};


#endif