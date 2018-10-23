#include <iostream>
#include <vector>
using namespace std;

int BruteForceMatch(string T,int n , string P, int m){
    int j;
    for (int i = 0; i <= n - m; i++){
        j = 0;
        while ( j < m && T[i+j] == P[j]){
            //cout<<P[j];
            j++;
        }

        if (j == m) return i;
        
    }
    return -1;
}

vector<int> LastOcurrence(string P){
    vector<int> res(26,-1);
    int chr;
    for (int i = 0;i<P.size();i++){
        chr = P[i]-97;
        if (i > res[chr]) res[chr] = i;

    }
    return res;
}


void imp(vector<int> v){
    cout<<"Vector: | ";
    for(auto i : v){
        cout<<i<<" | ";
    }
    cout<<endl;
}


int BoyerMoore(string T,string P){
    auto L = LastOcurrence(P);
    int m = P.size();
    int i = m-1;
    int j = m-1;
    int l;
    do{
        if (T[i] = P[j]){
            if (j=0) return i;
            else {
                i--;
                j--;
            }
        }
        else{
            l = L[T[i]-97];
            i = i + m - min(j,1+l);
            j = m-1;
        }
    }
    while ( i > T.size()-1);
    return -1;
}


int main(){
    string T,P;
    cout<<"Ingrese un texto: ";
    cin>>T;
    cout<<"Ingrese un subtexto: ";
    cin>>P;
    int idx;
    // auto LOF = LastOcurrence(P);
    // cout<<"DOne";
    // imp(LOF);
    // cout<<min(1,5)<<endl;
    idx = BruteForceMatch(T,T.size(),P,P.size());
    idx = BoyerMoore(T,P);
    cout<<"Se encontro en: "<<idx<<endl;
    cout<<"Frase: ";
    for( int i = idx; i< idx + P.size();i++){
        cout<<T[i];
    }
    cout<<endl;


}