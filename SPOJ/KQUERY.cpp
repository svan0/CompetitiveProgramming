#include <bits/stdc++.h>
using namespace std;
struct qr{
    int k,l,r,idx;
    qr(int a,int b,int c,int d){
        k=a,l=b,r=c,idx=d;
    }
    bool operator<(const qr &o){
        if(k==o.k){
            if(l==o.l){
                return r<o.r;
            }
            return l<o.l;
        }
        return k<o.k;
    }
};
const int MAX = 30001;
int st[4*MAX];
vector<pair<int,int> > a;
vector<qr> queries;
int res[200001];
int n,q;
void build(int node,int l,int r){
    if(l==r){
        st[node]=1;
        return;
    }
    int mid = (l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    st[node] = st[2*node] + st[2*node+1];
}
int query(int node,int l,int r,int ql,int qr){
    if(l>qr || r<ql)return 0;
    if(l>=ql && r<=qr)return st[node];
    int mid = (l+r)/2;
    return query(2*node,l,mid,ql,qr)+query(2*node+1,mid+1,r,ql,qr);
}
void update(int node,int l,int r,int ql,int qr){
    if(l>qr || r<ql)return ;
    if(l>=ql && r<=qr){st[node] = 0;return;}
    int mid = (l+r)/2;
    update(2*node,l,mid,ql,qr);
    update(2*node+1,mid+1,r,ql,qr);
    st[node]=st[2*node]+st[2*node+1];
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int v;
        scanf("%d",&v);
        a.push_back(make_pair(v,i));
    }
    sort(a.begin(),a.end());
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        queries.push_back(qr(k,l-1,r-1,i));
    }
    sort(queries.begin(),queries.end());
    build(1,0,n);
    int pos = 0;
    for(int i=0;i<q;i++){
        while(pos<n && a[pos].first <= queries[i].k){
            update(1,0,n,a[pos].second,a[pos].second);
            pos++;
        }
        res[queries[i].idx] = query(1,0,n,queries[i].l,queries[i].r);
    }
    for(int i=0;i<q;i++)printf("%d\n",res[i]);
}
