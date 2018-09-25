#ifndef HASH_H
#define HASH_H
#include <algorithm>
#include <boost/algorithm/string.hpp>   
#include "hashNode.h"

int dispFunction(string value){
    int res = 0;
    
    int i=0;
    unsigned char a;
    while(value[i]!='\0'){
        a = value[i];
        res = res + int(a) * i+1;
        i++;
    }
    return res;
        
}

class Hash
{
    private:
        vector < hashNode* > table;
    public:
        Hash(){
            this->table.assign(80383,0);
        }

        bool get(string palabra){
            boost::algorithm::to_lower(palabra);
            int llave = dispFunction(palabra);
            if (table[llave]){
                auto it = find(table[llave]->values.begin(),table[llave]->values.end(),palabra);
                return it != table[llave]->values.end();
            }
            return false;
        }


        void put(string key){
            boost::algorithm::to_lower(key);
            int llave = dispFunction(key);
            if (table[llave]){
                //cout<<"Existe llave"<<endl;
                auto it = find(table[llave]->values.begin(),table[llave]->values.end(),key);
                if (it == table[llave]->values.end())
                    table[llave]->values.push_back(key);
            }
            else{
                //cout<<"NO Existe llave"<<endl;
                table[llave]=new hashNode(llave,key);
            }
        }

        void show(){
            for(auto& i : table){
                if (i)
                    cout<<(*i);
            }
        }

};



#endif