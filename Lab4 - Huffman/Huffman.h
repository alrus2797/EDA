#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "Arbol.h"
#include <map>
#include <vector>

class Huffman{
    private:
        Arbol <char>* HuffmanTree;
        map<char,int> frecuencies;
    public:
        Huffman(map<char,int> frecuencies){
            this->HuffmanTree = new Arbol<char>;
            this->frecuencies = frecuencies;

        }

        
        
};


#endif