#include <bits/stdc++.h>
using namespace std;
int N,j,k;
int max_node, max_val;
vector<int> tree[5050];
vector<int> path;
set<int> best,worst;
void dfs(int u,int par, int current_d){
    path.push_back(u);
    if(current_d > max_val){
        best.clear();
        worst.clear();
        max_val = current_d;
        max_node = u;
    }
    if(current_d == max_val){
        worst.insert(path[0]);
        worst.insert(u);

        if(current_d % 2 == 0){
            best.insert(path[current_d/2]);
        }
        else{
            best.insert(path[current_d/2]);
            best.insert(path[current_d/2 + 1]);
        }
    }
    for(int i=0;i<tree[u].size();i++){
        int v = tree[u][i];
        if(v != par){
            dfs(v,u,current_d + 1);
        }
    }
    path.pop_back();
}
int main(){
    //freopen("test.in", "r+", stdin);
    while(cin>>N){
        for(int i=1;i<5050;i++)tree[i].clear();
        best.clear();
        worst.clear();
        path.clear();
        max_val = -1;
        max_node = -1;


        for(int i=1;i<=N;i++){
            cin>>k;
            while(k--){
                cin>>j;
                tree[i].push_back(j);
            }
        }

        dfs(1,-1,0);
        worst.clear();
        best.clear();
        path.clear();

        int new_start = max_node;
        dfs(new_start, -1, 0);
        for(set<int>::iterator it = worst.begin(); it!=worst.end(); it++){
            int node = *it;
            if(node != new_start){
                path.clear();
                dfs(node, -1, 0);
                break;
            }
        }
        cout<<"Best Roots  :";
        for(set<int>::iterator it = best.begin(); it!=best.end(); it++)cout<<" "<<*it;
        cout<<endl;
        cout<<"Worst Roots :";
        for(set<int>::iterator it = worst.begin(); it!=worst.end(); it++)cout<<" "<<*it;
        cout<<endl;

    }
}
