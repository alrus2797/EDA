#ifndef HNODO_H
#define HNODO_H


#include <iostream>
using namespace std;

string operator+(const string& a, const int& b) { //outside the class
    return a + to_string(b);
}

string operator+(const string& a, const char& b) { //outside the class
    return a + to_string(b);
}

class hNodo
{
    private:
        char letra;
        int frecuencia;
        hNodo* izq;
        hNodo* der;
        hNodo* padre;
        bool hoja;

        string camino;

        int id;

    public:
        hNodo(char letra, int frecuencia);
        hNodo(int frecuencia);
        string getStrValue();
        ~hNodo();

    bool operator < (const hNodo& a){
        if (this->frecuencia < a.frecuencia) return true;
        return false;
    }

    friend ostream& operator<< (ostream& os, const hNodo& obj);
    friend bool operator> (const hNodo& a,  const hNodo& b);
    friend hNodo* operator + ( hNodo&,  hNodo&);

    friend class Huffman;
};

bool operator> (const hNodo& a,  const hNodo& b){
    return a.frecuencia > b.frecuencia;
}


//Constructor para nodos
hNodo::hNodo(char letra, int frecuencia)
{
    this->letra = letra;
    this->frecuencia = frecuencia;
    this->izq = 0;
    this->der = 0;
    this->padre = 0;
    this->hoja = true;
}


//Constructor para nodos padre
hNodo::hNodo( int frecuencia)
{
    this->frecuencia = frecuencia;
    this->izq = 0;
    this->der = 0;
    this->padre = 0;
    this->hoja = false;
}

hNodo::~hNodo()
{
}


hNodo* operator + (hNodo& a, hNodo& b){
    hNodo* nuevo = new hNodo(a.frecuencia+b.frecuencia);
    nuevo->izq = &a;
    nuevo->der = &b;
    return nuevo;
}

ostream& operator<< (ostream& os, const hNodo& obj) {
    if (obj.hoja) cout<<" ('"<<obj.letra<<"', "<<obj.frecuencia<<") ";
    else cout<<" ("<<obj.frecuencia<<") ";
    return os;
}

string hNodo::getStrValue(){
    string res ="";
    if (this->hoja) res = res +" ('"+this->letra+"', "+this->frecuencia+") ";
    else res = res +" ("+this->frecuencia+") ";
    res = res + "\n" + this->camino;
    return res;
}




#endif