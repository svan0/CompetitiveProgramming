#include <bits/stdc++.h>
using namespace std;
int T;
bool prime[2020];
map<char,int> mp;
string s;
vector<char> res;
void sieve(){
    memset(prime,1,sizeof prime);
    prime[0] = prime[1] = 0;
    for(int i=2;i<=2000;i++)
        if(prime[i])
            for(int j=2*i;j<=2000;j+=i)
                prime[j]=0;
}
int main(){
    sieve();
    cin>>T;
    for(int t=1;t<=T;t++){
        mp.clear();
        res.clear();
        cin>>s;
        for(int i=0;i<s.size();i++)mp[s[i]]++;
        for(map<char,int>::iterator it = mp.begin();it!=mp.end();it++)
            if(prime[it->second])
                res.push_back(it->first);
        cout<<"Case "<<t<<": ";
        if(res.size()==0){cout<<"empty"<<endl;continue;}
        sort(res.begin(),res.end());
        for(int i=0;i<res.size();i++)
            cout<<res[i];
        cout<<endl;
    }
}
