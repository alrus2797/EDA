#include <iostream>
using namespace std;
#include "Arbol.h"
int main(int argc, char const *argv[])
{
    cout<<"Hello!"<<endl;
    string a="Hola";
    for (auto i: a)
    {
        cout<<i<<endl;

    }
    Nodo* b = new sNodo("+");
    b->izq = new iNodo(1);
    b->der = new iNodo(10);
    cout<<b->getValue()<<endl;
    list<string> post = {"1","2","+","3","4","5","+","*","*"};
    cout<<isdigit(post.front()[0])<<endl;
    Arbol c(post);
    return 0;
}
