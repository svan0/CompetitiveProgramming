
#include <bits/stdc++.h>
using namespace std;
int N,l,r;
bool prime[1000001];
int res[1000001];
bool sumP(int p){
    int sum = 0;
    while(p)sum+=p%10, p/=10;
    return prime[sum];
}
void sieve(){
    memset(prime,1,sizeof prime);
    prime[0] = prime[1] = 0;
    for(int i=2;i<=1000000;i++)
        if(prime[i]){
            if(sumP(i))res[i] = 1;
            for(int j=2*i;j<=1000000;j+=i)
                prime[j]=0;
        }
    for(int i=1;i<=1000000;i++)res[i]+=res[i-1];
}
int main(){
    sieve();
    cin>>N;
    while(N--){
        cin>>l>>r;
        cout<<res[r] - res[l-1]<<endl;
    }
}
