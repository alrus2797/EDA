#include "Arbol.h"
#include <vector>
int main(int argc, char const *argv[])
{
    Arbol<int> a;
    vector<int> v = {11,6,8,19,4,10,5,50,17,43,49,31};
    for (auto i : v)
        a.push(i);
    //a.show();
    cout<<a.getDot()<<endl;
    return 0;
}
