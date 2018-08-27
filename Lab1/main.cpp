
#include "VLista.h"
#include "VCola.h"
#include "VPila.h"

#include "PLista.h"
#include "PCola.h"
#include "PPila.h"


int main()
{
    PPila a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.show();
    a.pop();
    a.show();
    a.pop();
    a.show();
    a.pop();
    a.show();
}



int maino()
{
    VCola<5> a;
    a.show();
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(4);

    cout<<endl;
    a.show();
    cout<<endl<<"Vacio antes: "<< a.isEmpty()<<endl;
    cout<<a.pop()<<endl;
    a.show();
    cout<<a.pop()<<endl;
    a.show();
    cout<<a.pop()<<endl;
    a.show();
    cout<<a.pop()<<endl;
    a.show();
    cout<<a.pop()<<endl;
    a.show();

    cout<<endl<<"Vacio Despues: "<< a.isEmpty()<<endl;
    return 0;
}