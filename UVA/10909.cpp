#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000000+1;
//const int MAX = 202;
int lucky[MAX];
int st[4*MAX];
int find_k(int node,int l,int r,int k){
    if(l==r)return l;
    int mid = (l+r)/2;
    if(st[2*node + 1] >= k)return find_k(2*node+1,l,mid,k);
    return find_k(2*node+2, mid+1,r,k-st[2*node+1]);
}
void remove_k(int node,int l,int r,int k){
    st[node]--;
    if(l==r){lucky[l] = 0;return;}
    int mid = (l+r)/2;
    if(st[2*node + 1] >= k)return remove_k(2*node+1,l,mid,k);
    return remove_k(2*node+2, mid+1,r,k-st[2*node+1]);
}
void build(int node,int l,int r){
    if(l==r){st[node] = lucky[l];return;}
    int mid = (l+r)/2;
    build(2*node + 1, l,mid);
    build(2*node + 2, mid+1, r);
    st[node] = st[2*node + 1] + st[2*node + 2];
}
void simul(){
    int total_so_far = 0;
    for(int k=0;6*k+1<MAX;k++){
        lucky[6*k+1]=1;total_so_far++;
        if(6*k+3<MAX)lucky[6*k+3]=1,total_so_far++;
    }
    build(0,1,MAX);
    for(int i=3;i<=total_so_far;i++){
        int val = find_k(0,1,MAX,i);
        for(int j = val, k = 0; j< total_so_far; j+=val, k++){
            remove_k(0,1,MAX,j-k);
            total_so_far--;
        }
    }
}
int main(){
    simul();
    //freopen("test.in","r+",stdin);
    int n;
    while(scanf("%d", &n) == 1){
        bool ok = false;

        int l1;
        if(n%2 ==0)
            for(l1=n/2;l1>0;l1--)
                if(lucky[l1] && lucky[n-l1]){
                    ok = true;
                    break;
                }
        if(ok)printf("%d is the sum of %d and %d.\n", n,l1,n-l1);
        else printf("%d is not the sum of two luckies!\n",n);

    }

}
