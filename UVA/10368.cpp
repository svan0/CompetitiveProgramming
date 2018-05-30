#include <bits/stdc++.h>
using namespace std;
bool win(int a,int b){
    if(a > b)return win(b,a);
    if(a == 0)return false;
    bool res = !win(b%a,a);
    if(b != a+b%a)res|=!win(a, a+b%a);
    return res;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        if(a==0 && b==0)break;
        cout<<(win(a,b)?"Stan wins":"Ollie wins")<<endl;
    }
}
