#include <iostream>
#ifndef PSTRUCTURE_H
#define PSTRUCTURE_H

#include "PNodo.h"

using namespace std;

class PStructure
{
    protected:
        PNodo* first;
        PNodo* last;
    public: 
        PStructure(){
            this->first=0;
            this->last=0;
        }
        void push(int v){
            PNodo* nuevo=new PNodo(v);
            if (last){
                last->siguiente=nuevo;
                last=nuevo;
                return;
            }
            first=last=nuevo;
            return;
        }

        void show()
        {
            PNodo* temp= this->first;
            cout<<"Lista: | ";
            while(temp)
            {
                cout<<temp->value<<" | ";
                temp=temp->siguiente;
            }
            cout<<endl;
        }

        void remove(int position){
            PNodo* temp=this->first;
            if (position==0){
                this->first=this->first->siguiente;

            }

            for(int i = 0; i < position-1; i++)
            {
                temp=temp->siguiente;
            }
            cout<<endl<<"Dato Borrado: "<<temp->value<<endl;
            if (!temp){
                return;
            }
            if (temp->siguiente && temp->siguiente != this->last){
                temp->siguiente=temp->siguiente->siguiente;
            }
            else if(temp->siguiente && temp->siguiente==last){
                temp->siguiente=0;
            }
            else if(!temp->siguiente){
                this->first=0;
                this->last=0;
            }
            
        }

        ~PStructure(){}
};

#endif