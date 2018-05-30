#include <bits/stdc++.h>
using namespace std;
int n;
bool prime[40001];
vector <int> P;
void sieve(){
    prime[0] = prime[1] = 0;
    for(int i=2;i<=40000;i++){
        if(prime[i]){
            P.push_back(i);
            for(int j=2*i;j<=40000;j+=i)prime[j]=0;
        }
    }
}
int goldbach(int n){
    int res = 0;
    for(int i=0;i<P.size() && n>=P[i];i++){
        if(prime[n - P[i]]){
            res++;
            if(P[i] == n - P[i])res++;
        }
    }
    return res/2;
}
int main(){
    memset(prime,1,sizeof prime);
    sieve();
    while(cin>>n && n!=0){
        cout<<goldbach(n)<<endl;;
    }
}
