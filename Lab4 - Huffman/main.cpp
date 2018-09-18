#include <iostream>
#include <fstream>

#include "Huffman.h"

using namespace std;


int main(){
    map<char,int> frecuencias;
    string frase;
    fstream file;
    file.open("frase.txt");
    string line;
    while (!file.eof()){
        getline(file,line);
        frase = frase + line;
    }
    int i = 0;
    cout<< frase <<endl;

    while(frase[i] != '\0'){

        if (frecuencias.find(frase[i]) != frecuencias.end()){
            frecuencias[frase[i]]++;
        }
        

        else{
            frecuencias[frase[i]]=1;
        }
        i++;
    }

    // for (auto i : frecuencias){
    //     cout<< i.first << "->" <<i.second <<endl;
    // }

    Huffman a(frecuencias);
    cout<<a.getDot()<<endl;
    
}