#include <iostream>

using namespace std;
struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *to,*next;
    long long *cap;
    int *last,*dist,*now,*q;
    flow_graph(){};
    flow_graph(int V,int MAX_E){
        MAX_V=V;
        to=new int[2*MAX_E],next=new int[2*MAX_E],cap=new long long[2*MAX_E];
        last=new int[MAX_V],dist=new int[MAX_V];
        now=new int[MAX_V],q=new int[MAX_V];
    }
    void clear(){
        fill(last,last+MAX_V,-1);
        E=0;
    }
    void add_edge(int u,int v,int uv,int vu=0){
        to[E]=v,next[E]=last[u],last[u]=E,cap[E++]=uv;
        to[E]=u,next[E]=last[v],last[v]=E,cap[E++]=vu;
    }
    bool bfs(){
        fill(dist,dist+MAX_V,-1);
        head=tail=0;
        q[tail]=t;++tail;
        dist[t]=0;
        while(head<tail){
            int v=q[head];head++;
            for(int e=last[v];e!=-1;e=next[e]){
                if(cap[e^1]>0 && dist[to[e]]==-1){
                    q[tail]=to[e];++tail;
                    dist[to[e]]=dist[v]+1;
                }
            }
        }
        return dist[s]!=-1;
    }
    long long dfs(int v,long long f){
        if(v==t)return f;
        for(int &e=now[v];e!=-1;e=next[e]){
            if(cap[e]>0 && dist[to[e]]==dist[v]-1){
                long long ret = dfs(to[e],min(f,cap[e]));
                if(ret>0){
                    cap[e]-=ret;
                    cap[e^1]+=ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    long long dinic(int src,int snk){
        s=src,t=snk;
        long long f=0,df;
        while(bfs()){
            for(int i=0;i<MAX_V;i++)now[i]=last[i];
            while(true){
                df=dfs(s,1LL<<60);
                if(df==0)break;
                f+=df;
            }
        }
        return f;
    }
};
int main() {
	int N,M;
	cin>>N>>M;
	flow_graph G(N,M);
	G.clear();
	for(int i=0;i<M;i++){
	    int a,b,c;
	    cin>>a>>b>>c;
	    G.add_edge(a-1,b-1,c,c);
	}
	cout<<G.dinic(0,N-1)<<endl;
}

