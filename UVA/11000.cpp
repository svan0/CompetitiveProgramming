#include <bits/stdc++.h>
using namespace std;
int n;
long long int m[100],f[100];
long long int F(int n);
long long int M(int n){
    if(m[n]!=-1)return m[n];
    if(n == 0)return m[n] = 0;
    if(n == 1)return m[n] = 1;
    return m[n] = M(n-1) + F(n-1);
}
long long int F(int n){
    if(f[n] != -1)return f[n];
    if(n == 0)return f[n] = 1;
    return f[n] = F(0) + M(n-1);
}
int main(){
    memset(m,-1,sizeof m);
    memset(f,-1,sizeof f);
    while(cin>>n){
        if(n==-1)break;
        cout<<M(n)<<" "<<M(n)+F(n)<<endl;
    }
}
