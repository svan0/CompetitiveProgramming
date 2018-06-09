//USING BIT
#include <bits/stdc++.h>
using namespace std;
int N,U,Q;
long long BIT[10101];
long long point_query(int idx){
    long long result=0;
    while(idx>0){
        result+=BIT[idx];
        idx-=(idx&-idx);
    }
    return result;
}
void update(int idx,int val){
    while(idx<=N){
        BIT[idx]+=val;
        idx+=(idx&-idx);
    }
}
void range_update(int l,int r,int val){
    update(l,val);
    update(r+1,-val);
}

int main() {
    int t;cin>>t;
    while(t--){
        memset(BIT,0,sizeof BIT);
        scanf("%d %d",&N,&U);
        while(U--){
            int l,r,val;
            scanf("%d %d %d",&l,&r,&val);
            l++;r++;
            range_update(l,r,val);
        }
        cin>>Q;
        while(Q--){
            int idx;
            scanf("%d",&idx);
            idx++;
            printf("%lld\n",point_query(idx));
        }
    }
    
}
//USING PREFIX SUM
#include <bits/stdc++.h>
using namespace std;
int N,U,Q;
long long upd[10101];

int main() {
    int t;cin>>t;
    while(t--){
        memset(upd,0,sizeof upd);
        scanf("%d %d",&N,&U);
        while(U--){
            int l,r,val;
            scanf("%d %d %d",&l,&r,&val);
            upd[l]+=val;
            upd[r+1]-=val;
        }
        for(int i=1;i<N;i++)upd[i] = upd[i-1]+upd[i];
        cin>>Q;
        while(Q--){
            int idx;
            scanf("%d",&idx);
            printf("%lld\n",upd[idx]);
        }
    }
    
}

