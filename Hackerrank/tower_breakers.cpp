#include <bits/stdc++.h>
using namespace std;
int T,N,M;
int main(){
    cin>>T;
    while(T--){
        cin>>N>>M;
        if(M==1 || N%2 == 0)cout<<2<<endl;
        else cout<<1<<endl;
    }
}
