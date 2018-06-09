#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T,N;
string buf;
struct Node {
  Node *next[10];
  bool ends;
  Node(){
      memset(next,NULL,sizeof next);
      ends = false;
  }
};
void insert(Node* root, string s){
    for(int i=0;i<s.length();i++){
        if(root->next[s[i]-'0']==NULL)
            root->next[s[i]-'0']=new Node;
        root=root->next[s[i]-'0'];
    }
    root->ends=true;
}
bool dfs(Node* u,bool found){
    if(u->ends && found)return true;
    for(int i=0;i<10;i++){
        if(u->next[i]!=NULL){
            if(dfs(u->next[i],found | u->ends))
                return true;
        }
    }
    return false;
}
void clear(Node *u){
    for(int i=0;i<10;i++){
        if(u->next[i]!=NULL){
            clear(u->next[i]);
        }
    }
    free(u);
}
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        Node *root = new Node;
        while(N--){
            cin>>buf;
            insert(root,buf);
        }
        cout<<(dfs(root,false)?"NO":"YES")<<endl;
        clear(root);
    }
}

