#include <iostream>
using namespace std;
#include "Arbol.h"


int main(int argc, char const *argv[])
{
    list<string> post = {"12","25","+","31","40","55","+","*","*"};


    Arbol c(post);
    cout<<c.getDot()<<endl;


    return 0;
}
