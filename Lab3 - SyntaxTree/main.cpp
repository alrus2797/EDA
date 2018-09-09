#include <iostream>
using namespace std;
#include "Arbol.h"
int main(int argc, char const *argv[])
{
    list<string> post = {"1","2","+","3","4","5","+","*","*"};

    Arbol c(post);
    return 0;
}
