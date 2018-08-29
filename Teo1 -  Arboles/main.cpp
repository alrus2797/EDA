#include "Arbol.h"
#include <vector>
int main(int argc, char const *argv[])
{
    Arbol<int> a;
    vector<int> v = {11,6,8,19,4,10,5,17,43,49,31};
    for (auto i : v)
        a.push(i);
    a.show();
    cout<<"Exist: "<<a.exist(21)<<endl;
    a.remove(a.find(11));
    a.show();
    return 0;
}
