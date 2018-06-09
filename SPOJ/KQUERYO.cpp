#include <bits/stdc++.h>
using namespace std;
const int MAX = 30303;
vector<int> st[4*MAX];
int a[MAX];
void build(int node,int l,int r){
    if(l==r){
        st[node].push_back(a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    merge(st[2*node].begin(),st[2*node].end(),st[2*node+1].begin(),st[2*node+1].end(),back_inserter(st[node]));
}
int query(int node,int l,int r,int ql,int qr,int k){
    if(l>qr || r<ql)return 0;
    if(l>=ql && r<=qr){
        return st[node].size() - (upper_bound(st[node].begin(),st[node].end(),k) - st[node].begin());
    }
    int mid = (l+r)/2;
    return query(2*node,l,mid,ql,qr,k) + query(2*node+1,mid+1,r,ql,qr,k);
}
int main(){
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    build(1,0,n-1);
    cin>>q;
    int ans = 0;
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        l^=ans,r^=ans,k^=ans;
        ans = query(1,0,n-1,l-1,r-1,k);
        cout<<ans<<endl;
    }
}
