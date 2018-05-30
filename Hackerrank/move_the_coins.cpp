#include <bits/stdc++.h>
using namespace std;
int n,q,a,b,t;
int par[50505],depth[50505],c[50505];
int even_xor[50505],odd_xor[50505];
int st[50505],fin[50505];
vector<int> tree[50505];
void dfs(int u,int p){
    par[u] = p;
    if(p!=-1)depth[u] = depth[p]+1;
    st[u] = t++;
    if(depth[u] %2 == 0)even_xor[u] = c[u];
    else odd_xor[u] = c[u];
    for(int i=0;i<tree[u].size();i++){
        int v = tree[u][i];
        if(depth[v] == -1){
            dfs(v,u);
            even_xor[u]^=even_xor[v];
            odd_xor[u]^=odd_xor[v];
        }
    }
    fin[u] = t++;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    memset(depth,-1,sizeof depth);
    par[1] = -1;
    depth[1] = 0;
    t= 1;
    dfs(1,-1);
    int xor_sum = 0;
    for(int i=1;i<=n;i++)if(depth[i]%2==1)xor_sum^=c[i];
    cin>>q;
    while(q--){
        cin>>a>>b;
        if(st[b] > st[a] && fin[b] < fin[a]){cout<<"INVALID"<<endl;continue;}
        int new_xor_sum = xor_sum;
        if(depth[a]%2==depth[b]%2)new_xor_sum^=odd_xor[a] ^ even_xor[a];
        cout<<(new_xor_sum?"YES":"NO")<<endl;
    }
}
