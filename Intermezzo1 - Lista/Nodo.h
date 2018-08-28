#ifndef NODO_H
#define NODO_H

#include  <iostream>
using namespace std;

template <class T>
class Lista;

template<class O>
class Nodo
{
private:
    O value;
    Nodo<O> *siguiente;
public:
    Nodo(O value){
        this->value = value;
        this->siguiente = 0;
    }


    ~Nodo(){

    }
friend class Lista<O>;

};


#endif