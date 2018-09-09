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
    Arbol(list<string>);
    void showStack();
    void showR(Nodo*, int);
    void show();
    void generateDot(string&, Nodo*);
    void setIDs(Nodo* t, int&, string&);
    string getDot();
    ~Arbol();
};


Arbol::Arbol(list<string> post){
    int v;
    string vs;
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
    }

    if (pila.size()==1){
        this->root=pila.front();
        this->pila.clear();
    }
    else{
        cout<<"There's some error."<<endl;
        cout<<"Arbol"<<endl;
    }
    cout<<endl;
}

void Arbol::showStack(){
    cout<<"Stack: | ";
    for(auto& i: this->pila){
        i->getRawValue();
        cout<<" | ";
    }
    cout<<endl;
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

void Arbol::show(){
    this->showR(this->root,0);
}


void Arbol::generateDot(string& res, Nodo* t){
    if (!t) return;

    if (t->izq) res = res +  t->id + " -> " + t->izq->id + "; \n";
    if (t->der) res = res +  t->id + " -> " + t->der->id + "; \n";
    generateDot(res,  t->izq);
    generateDot(res,  t->der);   
}

void Arbol::setIDs(Nodo* t, int& i,string& res){
    if (!t) return;
    t->id = i;
    res = res + i + " [ label = \"" + t->getStrValue() + "\" ]; \n";
    i = i + 1;
    setIDs(t->izq,i, res);
    setIDs(t->der,i, res);
}

string Arbol::getDot(){

    string res = "digraph G {\n";
    int i = 0;
    this->setIDs(this->root, i, res);
    this->generateDot(res, this->root);

    res = res + "Resultado -> " + this->root->getValue() + "; \n";
    res = res + "}";
    return res;
}


Arbol::~Arbol()
{
}


#endif