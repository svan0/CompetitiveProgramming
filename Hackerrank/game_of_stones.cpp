#include <bits/stdc++.h>
using namespace std;
int T,n;
bool win[101];
int main(){
    win[0] = win[1] = false;
    for(int i=2;i<=100;i++){
        win[i] = !win[i-2];
        if(i>=3)win[i]|=!win[i-3];
        if(i>=5)win[i]|=!win[i-5];
    }
    cin>>T;
    while(T--){
        cin>>n;
        cout<<(win[n]?"First":"Second")<<endl;
    }
}
