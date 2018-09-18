#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>
#include <list>

using namespace std;

template<class T, class O>
class hashNode
{
private:
    T key;
    list<O> values;
    
public:
    hashNode(T key, O value){
        this->key = key;
        this->values.push_back(value);
    }
};



#endif