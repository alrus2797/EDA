#ifndef HASH_H
#define HASH_H
#include <algorithm>
#include <boost/algorithm/string.hpp>   
#include <string>

#include <cctype>
#include <fstream>
#include "hashNode.h"

int dispFunction(string value, int modulo = 0){
    int res = 0;
    
    int i=0;
    unsigned char a;
    while(value[i]!='\0'){
        a = value[i];
        res = res + int(a) * i+1;
        i++;
    }
    if (modulo)
        return res%modulo;
    else
        return res;
}

template< int N>
class Hash
{
    private:
        vector < hashNode* > table;
    public:
        Hash(){
            this->table.assign(N,0);
        }

        bool get(string palabra){
            boost::algorithm::to_lower(palabra);
            int llave = dispFunction(palabra,N);
            if (table[llave]){
                auto it = find(table[llave]->values.begin(),table[llave]->values.end(),palabra);
                return it != table[llave]->values.end();
            }
            return false;
        }

        void fill (string archivo){
            string frase;
            fstream file;
            file.open(archivo);
            string line;
            while (!file.eof()){
                getline(file,line);
                this->put(line);
            }
        }


        void put(string key){
            boost::algorithm::to_lower(key);
            int llave = dispFunction(key,N);
            //cout<<key<<" "<<llave<<endl;
            if (table[llave]){
                //cout<<"Existe llave"<<endl;
                if (!this->get(key))
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