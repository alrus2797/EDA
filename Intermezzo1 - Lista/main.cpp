#include "Lista.h"

int main(int argc, char const *argv[])
{
    Lista<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.show();
    a.remove(0);
    a.show();
    a.remove(0);
    a.show();
    a.remove(0);
    a.show();
    a.remove(0);
    a.show();
    cout<<"Encontro: "<<a.find(5)<<endl;
    a.remove(0);
    a.show();
    a.push_front(5);
    a.push_front(4);
    a.push_front(3);
    a.push_back(6);
    a.show();
    return 0;
}
