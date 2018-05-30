#include <bits/stdc++.h>
using namespace std;
int n,c;
bool prime[10000001];
vector <int> P;
void sieve(){
    prime[0] = prime[1] = 0;
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
            cout<<n<<" = "<<P[i]<<" + "<<n-P[i]<<endl;
            return;
        }
    }
}
int main(){
    memset(prime,1,sizeof prime);
    sieve();
    while(cin>>n && n!=0){
        goldbach(n);
    }
}
