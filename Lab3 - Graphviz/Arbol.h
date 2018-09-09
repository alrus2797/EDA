#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

template<typename T>
class Arbol
{
private:
    Nodo<T>* root;
public:
    Arbol(){
        this->root = 0;
    }


    void push(T value, Nodo<T>*& r){
        if (!r){
            r = new Nodo<T>(value);
            return;
        }
        else{
            push(value,r->children[value > r->value ]);
        }
    }

    void push(T value){
        this->push(value, this->root);
    }

    void showR(Nodo<T>* r, int i){
        if(!r) return;
        i += 4;
        showR(r->children[1],i);
        for(int j = 0; j < i; j++)
            cout<<" ";
        cout<<r->value<<endl;
        showR(r->children[0],i);
    }

    void show(){
        this->showR(this->root,0);
        cout<<endl;
    }

    Nodo<T>* find(T value, Nodo<T>*& r){
        if (!r) return 0;
        if (r->value == value) return r;
        this->find(value, r->children[r->value < value]);
    }

    Nodo<T>* find(T value){
        return find(value,this->root);
    }

    bool exist(T value){
        Nodo<T>* f = find(value, this->root);
        if (f) return true;
        return false;
    }

    void remove(Nodo<T>* temp){
        //Nodo<T>* temp = find(value, this->root);
        if (temp)
            cout<<"Antes de: "<<temp->value<<endl;
        else
            cout<<"Antes de: no existe"<<endl;
        if (temp){
            Nodo<T>* father = temp->father(this->root);
            cout<<"Padre: "<<father<<endl;
            //Si no tiene padre 
            //Tiene un solo hijo (XOR)
            if (!(temp->children[0] && temp->children[1]) && (temp->children[0] || temp->children[1])){
                cout<<"Un solo hijo"<<endl;
                if (temp->children[0])
                    father->children[ temp->value > father->value ] = temp->children[0];
                else
                    father->children[ temp->value > father->value ] = temp->children[1];
            }
            //Si es una hoja
            else if (!temp->children[0] && !temp->children[1]) {
                cout<<"Hoja"<<endl;
                father->children[ temp->value > father->value ] = temp;
            }

            //Si esta en medio
            else if (temp->children[0] && temp->children[1]){
                Nodo<T>* leftMax = temp->children[0];

                while (leftMax->children[1]){
                    leftMax = leftMax->children[1];
                }
                cout<<"Medio"<<endl;
                T vTemp = leftMax->value;
                leftMax->value = temp->value;
                temp->value = vTemp;
                cout<<leftMax->value<<" asd"<<endl;
                this->show();
                this->remove(leftMax);
            }
        }
        cout<<"The element is not in the Tree"<<endl;
    }

    void generateDot(string& res, Nodo<T>* t){
        if (!t) return;

        if (t->children[0]) res = res +  to_string(t->value) + " -> " + to_string(t->children[0]->value) + "; \n";
        if (t->children[1]) res = res +  to_string(t->value) + " -> " + to_string(t->children[1]->value) + "; \n";
        generateDot(res,  t->children[0]);
        generateDot(res,  t->children[1]);   
    }

    string getDot(){
        string res = "digraph G {\n";
        this->generateDot(res, this->root);
        res = res + "}";
        return res;
    }

};


#endif