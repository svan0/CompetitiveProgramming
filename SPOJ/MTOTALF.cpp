#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int c_i(char c){
	if(c>='A' && c<='Z')return c-'A';
	else return c-'a'+26;
}
int G[60][60],parent[60],visited[60];
bool bfs(int s,int t){
    memset(visited,0,sizeof visited);
    queue<int> q;
    q.push(s);
    visited[s]=1;
    parent[s]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<52;v++){
            if(!visited[v] && G[u][v]>0){
                q.push(v);
                parent[v]=u;
                visited[v]=1;
            }
        }
    }
    return visited[t]==1;
}
int ford_fulkerson(int s,int t){
    int max_flow=0;
    while(bfs(s,t)){
        int path_flow=10000000;
        for(int v=t;v!=s;v=parent[v])
            path_flow=min(path_flow,G[parent[v]][v]);
        for(int v=t;v!=s;v=parent[v]){
            G[parent[v]][v]-=path_flow;
            G[v][parent[v]]+=path_flow;
        }
        max_flow+=path_flow;
    }
    return max_flow;
}
int main() {
	int E;
	cin>>E;
	while(E--){
	    char u,v;int w;
	    cin>>u>>v>>w;
	    G[c_i(u)][c_i(v)]+=w;
	}
	cout<<ford_fulkerson(0,25)<<endl;
}

