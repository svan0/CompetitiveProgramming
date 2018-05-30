#include <bits/stdc++.h>
using namespace std;
int n;
map<int,bool> win;
bool whowin(int p){
    if(win.find(p) != win.end())return win[p];
    if(p>=n)return win[p] = false;
    for(int i=2;i<=9;i++){
        if(!whowin(p*i))return win[p]=true;
    }
    return win[p] = false;
}
int main(){
    while(cin>>n){
        win.clear();
        if(whowin(1))cout<<"Stan wins."<<endl;
        else cout<<"Ollie wins."<<endl;
    }
}
