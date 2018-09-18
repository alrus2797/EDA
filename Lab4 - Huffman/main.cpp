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
    while(frase[i] != '\0'){
        if (frecuencias.find(frase[i]) != frecuencias.end()){
            frecuencias[frase[i]]++;
        }
        else{
            frecuencias[frase[i]]=1;
        }
        i++;
    }

    Huffman a(frecuencias);
    cout<<"//"<<a.encriptar(frase)<<endl;
    string enc ="10100111101101111100101100100011100011011001010101100101111110111001110101110001000110001001100001011111000110101001101000011111111001101110101001110";
    cout<<"//"<<a.desencriptar(enc)<<endl;
    cout<<a.getDot()<<endl;
    
}