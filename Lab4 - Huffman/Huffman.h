#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "hNodo.h"
#include <map>
#include <list>
#include <algorithm>

template<class T>
void imp(list<T>& l,string msg= "Vector: "){
    cout<<msg<<": ";
    for(auto i: l){
        cout<<(*i)<<",";
    }
    cout<<endl;
}

bool comparePNodos(hNodo*& i, hNodo*& j){
    return *i < *j;
}



class Huffman{
    private:
        map<char,int> frecuencies;
        hNodo* root;
    public:
        map<char,string> keys;
        Huffman(map<char,int> frecuencies){
            list<hNodo*> stack,hojas;
            
            for (auto i : frecuencies){
                stack.push_back( new hNodo(i.first, i.second) );
            }

            hojas = stack;

            hNodo* h1;
            hNodo* h2;
            hNodo* p;
            while (stack.size() > 1){
                stack.sort(comparePNodos);
                h1 = stack.front();
                stack.pop_front();
                h2 = stack.front();
                stack.pop_front();

                p = *h1 + *h2;
                h1->padre = p;
                h2->padre = p;
                stack.push_front(p);
            }
            this->root = *(stack.begin());

            hNodo* temp;
            string codigo;
            for (auto& i : hojas){
                temp = i;
                codigo = "";
                //cout<<"DEBUG: "<<temp->padre<<endl;
                while (temp != this->root){
                    if (temp->padre->izq == temp) codigo = codigo + "0";
                    if (temp->padre->der == temp) codigo = codigo + "1";
                    temp = temp->padre;
                }
                reverse(codigo.begin(),codigo.end());
                i->camino = codigo;
            }

            for (auto i: hojas) this->keys[i->letra] = i ->camino;

        }

        void showR(hNodo* r, int i){
            if(!r) return;
            i += 5;
            this->showR(r->der,i);
            for(int j = 0; j < i; j++)
                cout<<" ";
            cout<<*r<<endl;
            this->showR(r->izq,i);
        }

        void generateDot(string& res, hNodo* t){
            if (!t) return;

            if (t->izq) res = res +  t->id + " -> " + t->izq->id + "; \n";
            if (t->der) res = res +  t->id + " -> " + t->der->id + "; \n";
            generateDot(res,  t->izq);
            generateDot(res,  t->der);   
        }

        void setIDs(hNodo* t, int& i,string& res){
            if (!t) return;
            t->id = i;
            res = res + i + " [ label = \"" + t->getStrValue() + "\" ]; \n";
            i = i + 1;
            setIDs(t->izq,i, res);
            setIDs(t->der,i, res);
        }

        string getDot(){

            string res = "digraph G {\n";
            int i = 0;
            this->setIDs(this->root, i, res);
            this->generateDot(res, this->root);

            res = res + "}";
            return res;
        }

        string encriptar (string texto){
            string res = "";
            int i = 0;
            while (texto[i] != '\0'){
                res =  res + this->keys[texto[i]];
                i++;
            }
            return res;
        }

        string desencriptar (string texto){
            string res = "";
            int i = 0;
            hNodo* temp;
            while (texto[i] != '\0'){
                temp =  this->root;
                while (!temp->hoja){
                    if (texto[i] == '0') temp = temp->izq;
                    if (texto[i] == '1') temp = temp->der;
                    i++;
                }
                if (temp) res = res + string(&temp->letra);
            }
            return res;
        }
        
};


#endif