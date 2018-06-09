#include <bits/stdc++.h>
using namespace std;
long long int c[101][101];
long long int C(int n,int k){
    if(c[n][k] != -1)return c[n][k];
    if(k == 0 || n == k)return c[n][k] = 1;
    return c[n][k] = C(n-1,k-1) + C(n-1, k);
}
int main(){
    int n,k;
    memset(c,-1,sizeof c);
    while(cin>>n>>k && n!=0){
        cout<<n<<" things taken "<<k<<" at a time is "<<C(n,k)<<" exactly.\n";
    }
}
