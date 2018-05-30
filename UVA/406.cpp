#include <bits/stdc++.h>
using namespace std;
int n,c;
bool prime[1010];
bool done[1010];
vector <int> P;
void sieve(){
    P.clear();
    P.push_back(1);
    for(int i=2;i<=n;i++){
        if(prime[i]){
            P.push_back(i);
            if(!done[i]){
                done[i] = true;
                for(int j=2*i;j<1010;j+=i)prime[j]=false;
            }
        }
    }
}
int main(){
    memset(prime,1,sizeof prime);
    while(cin>>n>>c){
        sieve();
        //cout<<P.size()<<endl;
        cout<<n<<" "<<c<<":";
        int a = max(0,(int)P.size()/2 - c + (int)P.size()%2);
        int b = min(P.size(), P.size()/2 + c);
        for(int i = a; i<b; i++)cout<<" "<<P[i];
        cout<<endl<<endl;
    }
}
