#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int oo = (int) 1e9;
const int mod = (int) 1e9 + 7;
const double PI = acos(-1.0);
 
const int N = 1010, E = 40001;
int n,e;
int R[N],L[N];
int head[N], to[E], nxt[E];
int vis[N], vid;
int w[N],l[N],h[N];
 
void init()
{
    e =0;
    memset(head,-1,2*n*(sizeof head[0]));
}
 
void addEdge(int f,int t)
{
    nxt[e] = head[f];
    head[f] = e;
    to[e++] = t;
}
 
bool can(int u)
{
    if(vis[u] == vid) return false;
    vis[u] = vid;
    for(int k=head[u];~k;k=nxt[k]){
        int v = to[k];
        if(R[v] == -1 || can(R[v])){
            R[v] = u;
            L[u] = v;
            return true;
        }
    }
    return false;
}
 
int match()
{
    int res = 0;
    memset(R, -1, sizeof R);
    for(int i=0;i<n;i++){
        vid++;
        if(can(i)) res++;
    }
    return res;
}
 
int main()
{
    while(scanf("%d",&n)==1&&n){
		init();
		for(int i=0;i<n;i++)
			scanf("%d %d %d",w+i,l+i,h+i);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j && w[i]>w[j] && h[i]>h[j] && l[i]>l[j])
					addEdge(2*j+1,2*i);
		n*=2;
		printf("%d\n", n/2-match());
	}
    return 0;
}
