#include "Hash.h"
#include <map>


using namespace std;

int maino(){
    // hashNode<int,string>* h1 =  new hashNode<int,string>(13,"asd");
    // hashNode<int,string>* h2 =  new hashNode<int,string>(14,"qwe");
    // hashNode<int,string>* h3 =  new hashNode<int,string>(15,"hjfg");
    // hashNode<int,string>* h4 =  new hashNode<int,string>(16,"oiuqwe");
    // cout<< (*h1 == *h2) <<endl;
    // list<hashNode<int,string>> l = {*h1,*h2,*h3,*h4};
    // int a = 15;
    // auto it = find(l.begin(),l.end(),a);
    // cout<<*it<<endl;

    Hash<1500> ha;
    ha.put("palabra");
    ha.put("palabra");
    ha.put("palabrota");
    ha.show();
    
    return 0;    
}

int main(int argc, char const *argv[])
{

    Hash<1500> nHash;
    nHash.fill("palabras/listado-general.txt");
    int i;
    string palabra;
    string query;

    cout<<"Ingrese una oración"<<endl;
    getline(cin,query);
    i=0;

    vector<string> palabras;

    string s = query;
    string delimiter = " ";

    size_t pos = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        palabra = s.substr(0, pos);
        palabras.push_back(palabra);
        s.erase(0, pos + delimiter.length());
    }
    palabras.push_back(s);
    cout<<endl;

    for(auto i:palabras){
        if (nHash.get(i)){
            cout<< i <<" esta bien escrita"<<endl;
        }
        else{
            cout<<i<<" no esta bien escrita"<<endl;
        }
        
    }

    
    return 0;
}