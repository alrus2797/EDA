#ifndef ARBOL_H
#define ARBOL_H

#include "iNodo.h"
#include "sNodo.h"
#include <list>

#include <ctype.h>

template<class T>
void showLista(list<T> a){
    cout<<"List: | ";
    for(auto i: a){
        cout<<i<<" | ";
    }
    cout<<endl;
}

class Arbol
{
private:
    Nodo* root;
    list<Nodo*> pila;
public:
    Arbol(string exp);
    Arbol(list<string>);
    void showStack();
    void showR(Nodo*, int);
    ~Arbol();
};

Arbol::Arbol(string exp)
{

}

void Arbol::showStack(){
    cout<<"Stack: | ";
    for(auto& i: this->pila){
        i->getRawValue();
        cout<<" | ";
    }
    cout<<endl;
}

Arbol::Arbol(list<string> post){
    cout<<"-------------------"<<endl;
    int v;
    string vs;

    cout<<"Expresion: ";
    showLista(post);
    while (!post.empty()){
        if(isdigit(post.front()[0])){
            v = stoi(post.front());
            pila.push_back(new iNodo(v));
            post.pop_front();
        }
        else{
            vs = post.front();
            Nodo* nuevo = new sNodo(vs);
            nuevo->der = this->pila.back();
            this->pila.pop_back();
            nuevo->izq = this->pila.back();
            this->pila.pop_back();
            pila.push_back(nuevo);
            post.pop_front();
        }

    this->showStack();
        
    }

    cout<<"Resultado: "<<pila.front()->getValue()<<endl;
    cout<<"Arbol"<<endl;
    this->showR(pila.front(),0);

    if (pila.size()==1){
        this->root=pila.front();
        this->pila.clear();
    }
    else{
        cout<<"There's some error."<<endl;
        cout<<"Arbol"<<endl;
        this->showR(pila.front(),0);
        this->pila.clear();
    }
    
}

void Arbol::showR(Nodo* r, int i){
    if(!r) return;
    i += 3;
    this->showR(r->der,i);
    for(int j = 0; j < i; j++)
        cout<<" ";
    r->getRawValue();
    cout<<endl;
    this->showR(r->izq,i);
}


Arbol::~Arbol()
{
}


#endif