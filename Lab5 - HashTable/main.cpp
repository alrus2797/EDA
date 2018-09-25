#include "Hash.h"
#include <map>
#include <cctype>
#include <fstream>

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

    Hash ha;
    ha.put("palabra");
    ha.put("palabra");
    ha.put("palabrota");
    ha.show();
    
    return 0;    
}

int main(int argc, char const *argv[])
{
    map<string,bool> dictionary;
    Hash nHash;
    string frase;
    fstream file;
    file.open("palabras/listado-general.txt");
    string line;
    int i;
    string palabra;
    unsigned char q = 'é';
    int qw = q;
    cout<<"asdsad"<<qw<<endl;
    while (!file.eof()){
        getline(file,line);
        //cout<<line<<endl;
        dictionary[line]=true;
        //cout<<line<<endl;
        nHash.put(line);
    }
    //nHash.show();
    
    string query;
    cout<<"Ingrese una palabra"<<endl;
    getline(cin,query);
    i=0;
    cout<<"Palabra: "<<query<<endl;
    if (nHash.get(query)){
        cout<<"Esta bien escrita"<<endl;
    }
    else{
        cout<<"No esta bien escrita"<<endl;
    }
    
    return 0;
}