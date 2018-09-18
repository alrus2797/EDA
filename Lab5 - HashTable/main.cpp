#include "Hash.h"
#include <map>
#include <cctype>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    map<string,bool> dictionary;
    string frase;
    fstream file;
    file.open("palabras/listado-general.txt");
    string line;
    int i;
    string palabra;
    while (!file.eof()){
        getline(file,line);
        //cout<<line<<endl;
        dictionary[line]=true;
    }
    
    string query;
    cout<<"Ingrese una palabra"<<endl;
    cin>>query;
    i=0;
    cout<<"Palabra: "<<query<<endl;
    if (dictionary.find( query ) != dictionary.end() ){
        cout<<"Esta bien escrita"<<endl;
    }
    else{
        cout<<"No esta bien escrita"<<endl;
    }
    
    return 0;
}