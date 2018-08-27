#ifndef VSTRUCTURE_H
#define VSTRUCTURE_H

#include <iostream>
using namespace std;


template <int N>

class VStructure
{
protected:
    int array[N];
    int actual;

public:
    VStructure(){
        this->actual=0;
        
        for(int i = 0; i < N; i++)
        {
            this->array[i]=0;
        }   
    }

    void push(int v){
       if (this->actual<N)
        {
            this->array[actual]=v;
            this->actual++;
        }
    }

    void show(){

        cout<<"Lista: | ";
        for(int i = 0; i < N; i++)
        {
            cout<<this->array[i]<<" | ";
        }   
        cout<<""<<endl;
    }

    void clear(){

        for(int i = 0; i < N; i++)
        {
            this->array[i]=0;
        }
        this->actual=0;
    }

    bool isEmpty(){
        
        if (actual==N)
            return false;
        return true;
    }

    bool isFull(){

        return !this->isEmpty();
    }

    ~VStructure(){

    }

};




#endif