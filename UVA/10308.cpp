#include <bits/stdc++.h>
using namespace std;

string in;
vector<pair<int,int> > tree[10101];
int max_node, max_val;
void dfs(int u,int par, int current_d){
    if(current_d > max_val){
        max_node = u;
        max_val = current_d;
    }
    for(int i=0;i<tree[u].size();i++){
        int v = tree[u][i].first;
        int w = tree[u][i].second;
        if(v!=par){
            dfs(v,u,current_d+w);
        }
    }
}
int main(){
    while(getline(cin,in)){
        if(in == ""){
            max_val = -1;
            dfs(1,-1, 0);
            max_val = -1;
            dfs(max_node,-1, 0);
            cout<<max_val<<endl;
            for(int i=1;i<=10000;i++)tree[i].clear();
            continue;
        }
        stringstream ss(in);
        int u,v,w;
        ss>>u>>v>>w;
        tree[u].push_back(make_pair(v,w));
        tree[v].push_back(make_pair(u,w));
    }
    max_val = -1;
    dfs(1,-1, 0);
    max_val = -1;
    dfs(max_node,-1, 0);
    cout<<max_val<<endl;
}
