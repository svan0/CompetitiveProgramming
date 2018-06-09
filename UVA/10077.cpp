#include <bits/stdc++.h>
using namespace std;
int n,m;
double rat;
void solve(){
    int lu = 0, ld = 1, mu = 1, md = 1, ru = 1, rd = 0;
    //int it = 0;
    while(mu!= n || md!= m){
        //if(it >  10)break;
        double _rat = 1.0*mu/md;
        //cout<<_rat<<" "<<rat<<endl;
        if(_rat > rat){
            cout<<"L";
            ru = mu, rd = md;
        }
        else{
            cout<<"R";
            lu = mu, ld = md;
        }
        mu = lu + ru, md = ld + rd;
        //it++;
    }
    cout<<endl;
}
int main(){
    while(cin>>n>>m && (n!=1 || m!=1)){
        rat = 1.0 * n / m;
        solve();
    }
}
