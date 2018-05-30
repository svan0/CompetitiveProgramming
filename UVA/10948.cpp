#include <bits/stdc++.h>
using namespace std;
int n;
bool prime[1000001];
vector <int> P;
void sieve(){
    prime[0] = prime[1] = 0;
    for(int i=2;i<=1000000;i++){
        if(prime[i]){
            P.push_back(i);
            for(int j=2*i;j<=100000;j+=i)prime[j]=0;
        }
    }
}
int goldbach(int n){
    for(int i=0;i<P.size() && n>=P[i];i++)
        if(prime[n - P[i]])
            return cout<<P[i]<<"+"<<n - P[i]<<endl, 0;
    return cout<<"NO WAY!"<<endl, 0;
}
int main(){
    memset(prime,1,sizeof prime);
    sieve();
    while(cin>>n && n!=0){
        cout<<n<<":"<<endl;
        goldbach(n);
    }
}
