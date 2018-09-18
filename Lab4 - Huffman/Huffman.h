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
        Huffman(map<char,int> frecuencies){
            list<hNodo*> stack;

            for (auto i : frecuencies){
                stack.push_back( new hNodo(i.first, i.second) );
            }
            imp(stack, "stack");

            //cout<<"comp: "<< comparePNodos(stack[0],stack[1])<<endl;
            hNodo* h1;
            hNodo* h2;
            hNodo* p;
            while (stack.size() > 1){
                //sort(stack.begin(), stack.end(),comparePNodos);
                stack.sort(comparePNodos);
                h1 = stack.front();
                stack.pop_front();
                h2 = stack.front();
                stack.pop_front();

                p = *h1 + *h2;
                stack.push_front(p);
            }
            this->root = *(stack.begin());
            //showR(this->root,0);
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



        
        
};


#endif