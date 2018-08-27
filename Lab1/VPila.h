#ifndef VPILA_H
#define VPILA_H

#include "VStructure.h"


template <int N>
class VPila : public VStructure<N>
{
public:
    VPila(){}
    ~VPila(){}

    int pop()
    {
        int res;
        // if (this->actual==N)
        //     res =  this->array[this->actual-1];
        // else

        this->actual--;
        res = this->array[this->actual];
        this->array[this->actual]=0;
        return res;
    }
};



#endif