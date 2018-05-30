#include <bits/stdc++.h>
using namespace std;
int n;
map<int,bool> mp;
bool solve(int n){
    if(mp.find(n)!=mp.end())return mp[n];
    if(n==0)return mp[n] = false;
    for(int i=n/2 + n%2 ;i<n;i++){
        if(!solve(i))return mp[n] = true;
    }
    return mp[n] = false;
}
int main(){
    while(cin>>n && n!=0)cout<<(solve(n)?"Alice":"Bob")<<endl;
}
