#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template <class T>
class Lista
{
private:
    Nodo<T>* first;
    Nodo<T>* last;
public:
    Lista(){
        this->first=0;
        this->last=0;
    }

    void push_back (T value){
        Nodo<T>* nuevo = new Nodo<T>(value);
        if (this->last){
            this->last->siguiente =  nuevo;
            this->last = nuevo;
        }
        else if (!this->first) {
            this->first =  nuevo;
            this->last = nuevo;
        }
    }
    void push_front(T value){
        Nodo<T>* nuevo = new Nodo<T>(value);
        if (!this->first){
            this->first = this->last = nuevo;
        }
        else{
            nuevo->siguiente = this->first;
            this->first =  nuevo;
        }
    }

    void remove(int position){
        Nodo<T>* ant = this->first;
        Nodo<T>* act = this->first->siguiente;

        //Al princpio
        if (position == 0){
            this->first = this->first->siguiente;
            delete ant;
            delete act;
            return;
        }
        if (position <0) return;

        int i = 0;
        while(i < position-1 && act){
            ant = ant->siguiente;
            act = act->siguiente;
            if (!act) return;
            i++;
        }

        //Final de la lista
        if (act == this->last){
            ant->siguiente=0;
            this->last =  ant;
            delete act;
        }
        //En el medio
        else{
            ant->siguiente = act->siguiente;
            delete act;
        }
    }

    void findP (T p, Nodo<T>**& n){
        if ((*n)->value == p) return ;
        if ((*n)->siguiente)
            n = &((*n)->siguiente);
        else{
            n = 0;
            return;
        }
        findP(p, n);
    }

    bool find(T p){
        if (p == this->first->value) return true;
        Nodo<T>* temp = this->first;
        while(temp){
            if ( p == temp->value) return true;
            temp = temp->siguiente;
        }
        return false;

    }



    void show(){
        if (!this->first){
            cout<<"List Empty"<<endl;
            return;
        }
        Nodo<T>* temp = this->first;
        cout<<"Lista: | ";
        while (temp){
            cout<<temp->value<<" | ";
            temp = temp->siguiente;
        }
        cout<< "\tf: "<<this->first->value <<" l: "<<this->last->value<<"   s: "<<this->size() ;
        cout<<endl;

    }

    int size(){
        if (!this->first) return 0;
        Nodo<T>* temp =  this-> first;
        int s = 0;
        while(temp){
            temp = temp->siguiente;
            s++;
        }
        return s;
    }
    ~Lista(){}
};




#endif