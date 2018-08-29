#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;


template <class T>
class Arbol;

template<typename T>
class Nodo
{
private:
    T value;
    Nodo<T>* children[2];
public:
    Nodo(T value){
        this->value =  value;
        children[0] = 0;
        children[1] = 0;
    }


    Nodo<T>* father(Nodo<T>* r){
        if (!r) return 0;
        r->children[0]  ? cout<<r->children[0]->value : cout<<0 ;
        cout<<" - ";
        r->children[1]  ? cout<<r->children[1]->value : cout<<0 ;
        cout<<" -> "<<this->value<<" r: "<<r->value<<endl;
        if (r->children[0] && r->children[0]->value == this->value) return r;
        if (r->children[1] && r->children[1]->value == this->value) return r;
        this->father(r->children[ this->value < r->value ]);
        // //cout<<r->children[0]<<" - "<<r->children[1]<<" -> "<<this<<endl;
        // if (r->children[0] || r->children[1]){
        //     if (r->children[0] == this || r->children[1] == this) return r;
        //     this->father();
        // }

    }



    ~Nodo(){

    }
friend class Arbol<T>;
};


#endif