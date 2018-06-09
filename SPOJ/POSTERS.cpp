#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000001;
int st[4*MAX];
set<int> res;
void update(int node,int l,int r,int ql,int qr,int color){
    if(l>qr || r<ql)return;
    if(l>=ql && r<=qr){
        st[node]=color;
        return;
    }
    if(st[node]!=0){
        st[2*node]=st[node];
        st[2*node+1]=st[node];
        st[node] = 0;
    }
    int mid = (l+r)/2;
    update(2*node,l,mid,ql,qr,color);
    update(2*node+1,mid+1,r,ql,qr,color);
}
void cnt(int node,int l,int r,int ql,int qr){
    if(l>qr || r<ql)return;
    if(st[node]!=0){
        res.insert(st[node]);
        return;
    }
    if(l==r)return;
    int mid = (l+r)/2;
    cnt(2*node,l,mid,ql,qr);
    cnt(2*node+1,mid+1,r,ql,qr);
}
int main(){
    int T,n,l,r;
    cin>>T;
    while(T--){
        memset(st,0,sizeof st);
        res.clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>l>>r;
            update(1,0,MAX,l,r,i);
        }
        cnt(1,0,MAX,0,MAX);
        cout<<res.size()<<endl;
    }
}
