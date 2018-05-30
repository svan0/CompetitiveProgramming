#include <bits/stdc++.h>
using namespace std;
int n,c;
bool prime[10000001];
vector <int> P;
void sieve(){
    for(int i=2;i<=10000000;i++){
        if(prime[i]){
            P.push_back(i);
            for(int j=2*i;j<=10000000;j+=i)prime[j]=false;
        }
    }
}
void goldbach(int n){
    for(int i=0;i<P.size();i++){
        if(prime[n - P[i]]){
            cout<<P[i]<<" "<<n-P[i]<<endl;
            return;
        }
    }
}
int main(){
    memset(prime,1,sizeof prime);
    sieve();
    while(cin>>n){
        if(n<8){cout<<"Impossible."<<endl; continue;}
        if(n%2 == 0){cout<<"2 2 ";goldbach(n-4);}
        else {cout<<"2 3 ";goldbach(n-5);}
    }
}
