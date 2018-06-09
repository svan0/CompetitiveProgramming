#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010101;
int t[4*MAX],o[4*MAX],c[4*MAX];
string s;
void build(int node, int l,int r){
    if(l==r){
        if(s[l] == '(')o[node]=1;
        else c[node]=1;
        return;
    }
    int mid = (l+r)/2;
    build(2*node, l,mid);
    build(2*node + 1, mid+1,r);
    int tmp = min(o[2*node], c[2*node + 1]);
    t[node] = t[2*node] + t[2*node+1] + tmp;
    o[node] = o[2*node] + o[2*node+1] - tmp;
    c[node] = c[2*node] + c[2*node+1] - tmp;
}
pair<int,pair<int,int> > query(int node,int l,int r,int ql,int qr){
    if(l>qr || r<ql)return make_pair(0,make_pair(0,0));
    if(l>=ql && r<=qr){
        return make_pair(t[node],make_pair(o[node],c[node]));
    }
    int mid = (l+r)/2;
    pair<int,pair<int,int> > a = query(2*node,l,mid,ql,qr);
    pair<int,pair<int,int> > b = query(2*node + 1,mid+1,r,ql,qr);
    int tmp = min(a.second.first, b.second.second);
    return make_pair(a.first + b.first + tmp,
            make_pair(a.second.first + b.second.first - tmp,
            a.second.second + b.second.second - tmp));
}
int main(){
    cin>>s;
    build(1,0,s.length());
    int m;
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<2*query(1,0,s.length(),l-1,r-1).first<<endl;
    }
}
