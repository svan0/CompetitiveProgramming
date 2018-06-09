#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()

const int oo = (int) 1e9;
const int mod = (int) 1e9 + 7;
const double PI = acos(-1.0);

const int N = 1000, E = 1000001;
int n,m,e,src,snk;
int p,t,s,c;
int x[1000],y[1000];
int head[N], to[E], nxt[E], cap[E];
int vis[N], vid;
 
void init()
{
    e =0;
    memset(head,-1,n*(sizeof head[0]));
}
 
void addEdge(int f,int t,int c)
{
    nxt[e] = head[f];
    head[f] = e;
    cap[e] = c;
    to[e++] = t;
}
 
void addAugEdge(int f,int t,int c)
{
    addEdge(f,t,c);
    addEdge(t,f,0);
}
 
int dfs(int minEdge,int cur = src, int flow = INT_MAX)
{
    if(cur == snk) return flow;
    if(vis[cur] == vid || flow < minEdge) return 0;
    vis[cur] = vid;
    for(int k=head[cur];~k;k=nxt[k]){
        int t = to[k];
        int f;
        if(!(f=dfs(minEdge,t,min(flow, cap[k])))) continue;
        cap[k] -= f;
        cap[k^1] += f;
        return f;
    }
    return 0;
}
 
 
int maxFlow()
{
    if(src == snk) return oo;
    int res = 0, f;
    for(int edge = 1<<30 ; edge ; edge >>= 1)
        while(vid++, f=dfs(edge)) res += f;
    return res;
}
long long int dist(int i,int j){
    return 1LL*abs(x[i]-x[j])+1LL*abs(y[i]-y[j]);
}
int main()
{   
    int T;cin>>T;
    while(T--){
        cin>>p>>t>>s>>c;
        n=p+t+2;
        init();
        src = 0, snk = n-1;
        for(int i=t+1;i<n-1;i++)
            cin>>x[i]>>y[i];
        for(int i=1;i<=t;i++)
            cin>>x[i]>>y[i];
        for(int i=1;i<=t;i++)addAugEdge(src,i,1);
        for(int i=1;i<=t;i++)
            for(int j=t+1;j<n-1;j++)
                if(1LL*200*dist(i,j) <= 1LL*s*c)
                    addAugEdge(i,j,1);
        for(int i=t+1;i<n-1;i++)addAugEdge(i,snk,1);
        cout << maxFlow() << endl;
    }
    return 0;
}
