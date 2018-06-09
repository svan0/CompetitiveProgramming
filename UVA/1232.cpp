#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int st_m[4 * MAX];
int st_M[4 * MAX];
int lazy[4 * MAX];
int query_up(int node,int l,int r,int ql,int qr,int h){
    if(l>qr || r<ql)return 0;
    if(l != r){
        if(lazy[node] != 0){
            lazy[node<<1] = st_M[node<<1] = st_m[node<<1] = lazy[node];
            lazy[node<<1|1] = st_M[node<<1|1] = st_m[node<<1|1] = lazy[node];
            lazy[node] = 0;
        }
    }
    if(st_m[node] > h)return 0;

    if(l>=ql && r<=qr){
        if(st_M[node]<=h){
            lazy[node] = h;
            st_M[node] = h;
            st_m[node] = h;
            return r-l+1;
        }
    }

    int mid = (l+r)>>1;
    int res = query_up(node<<1,l,mid,ql,qr,h) + query_up(node<<1|1,mid+1,r,ql,qr,h);
    st_M[node] = max(st_M[node<<1], st_M[node<<1|1]);
    st_m[node] = min(st_m[node<<1], st_m[node<<1|1]);
    return res;
}
int main(){
    int c,n,l,r,h;
    scanf("%d",&c);
    while(scanf("%d",&n) == 1 && n!=0){
        memset(st_M,0,sizeof st_M);
        memset(st_m,0,sizeof st_m);
        memset(lazy,0,sizeof lazy);
        int res = 0;
        while(n--){
            scanf("%d %d %d", &l, &r,&h);
            res+=query_up(1,1,MAX,l,r-1,h);
        }
        printf("%d\n",res);
    }
}
