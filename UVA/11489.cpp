#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool win(int m0,int m1,int m2){
    if(m0 == -1 || m1 == -1 || m2 == -1) return true;
    int tot = (m1*1 + m2*2)%3;
    if(tot == 0)return !win(m0-1,m1,m2);
    if(tot == 1)return !win(m0,m1-1,m2);
    if(tot == 2)return !win(m0,m1,m2-1);
}
int main(){
    cin>>n;
    for(int t=1;t<=n;t++){
        cin>>s;
        int m0 = 0, m1 = 0, m2 = 0;
        for(int i=0;i<s.size();i++){
            if((s[i]-'0')%3==0)m0++;
            if((s[i]-'0')%3==1)m1++;
            if((s[i]-'0')%3==2)m2++;
        }
        cout<<"Case "<<t<<": ";
        cout<<(win(m0,m1,m2)?"S":"T")<<endl;
    }
}
