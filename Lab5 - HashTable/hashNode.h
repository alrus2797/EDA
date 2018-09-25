#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;


class hashNode
{
private:
    int key;
    list<string> values;
    
public:
    hashNode(int key, string value){
        this->key = key;
        this->values.push_back(value);
    }
    bool operator == ( const hashNode& h2){
        return this->key == h2.key;
    }
    bool operator == ( const int& h2){
        return this->key == h2;
    }

    friend class Hash;

    friend ostream& operator<< (ostream& os, hashNode h1){
        
        cout<< h1.key<<" -> | ";
        for (auto& i: h1.values ){
            cout<<i << " | ";
        }
        cout<<endl;
        return os;    
    }
};

// template<class T, class O>
// ostream& operator<< (ostream& os, const hashNode<T,O>& obj) {
//     cout<< obj.key<<" -> | ";
//     for (auto& i: obj.values ){
//         cout<<i << " | ";
//     }
//     cout<<endl;
//     return os;
// }





#endif