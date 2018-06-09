//USING SEGMENT TREE WITH LAZY PROPAGATION
#include <bits/stdc++.h>
using namespace std;
const int MAX_N=101000;
long long st[4*MAX_N],lazy[4*MAX_N];
int n,m,c,p,q;
long long v;
void init(){
	memset(st,0,4*n*(sizeof st[0]));
	memset(lazy,0,4*n*(sizeof lazy[0]));
}
void update(int cur,int ns,int ne,int qs,int qe,long long val){
	if(ns>ne)return;
	if(lazy[cur]!=0){
		st[cur]+=(ne-ns+1)*lazy[cur];
		if(ns!=ne){
			lazy[2*cur+1]+=lazy[cur];
			lazy[2*cur+2]+=lazy[cur];
		}
		lazy[cur]=0;
	}
	if(qs>ne || qe<ns)return;
	if(qs<=ns && qe>=ne){
		st[cur]+=(ne-ns+1)*val;
		if(ns!=ne){
			lazy[2*cur+1]+=val;
			lazy[2*cur+2]+=val;
		}
		return;
	}
	if(ns==ne){st[cur]+=val;return;}
	int mid=(ns+ne)/2;
	update(2*cur+1,ns,mid,qs,qe,val);
	update(2*cur+2,mid+1,ne,qs,qe,val);
	st[cur]=st[2*cur+1]+st[2*cur+2];
}
long long query(int cur,int ns,int ne,int qs,int qe){
	if(ns>ne)return 0;
	if(lazy[cur]!=0){
		st[cur]+=(ne-ns+1)*lazy[cur];
		if(ns!=ne){
			lazy[2*cur+1]+=lazy[cur];
			lazy[2*cur+2]+=lazy[cur];
		}
		lazy[cur]=0;
	}
	if(qs>ne || qe<ns)return 0;
	if(qs<=ns && qe>=ne)return st[cur];
	
	int mid=(ns+ne)/2;
	return query(2*cur+1,ns,mid,qs,qe)+query(2*cur+2,mid+1,ne,qs,qe);

}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		init();
		while(m--){
			scanf("%d %d %d",&c,&p,&q);
			p--,q--;
			if(!c){scanf("%lld",&v);update(0,0,n-1,p,q,v);}
			else printf("%lld\n",query(0,0,n-1,p,q));
		}
	}
}
//USING RANGE UPDATE RANGE QUERY BINARY INDEXED TREE
#include <bits/stdc++.h>
using namespace std;
const int MAX_N=101000;
int n,m,c,p,q;
long long v;
long long bit1[MAX_N],bit2[MAX_N];
void update(long long bit[], int i, long long v){
	for(;i<=n;i+=i&(-i))bit[i]+=v;
}
void update(int a,int b, long long v){
	update(bit1,a,v);
	update(bit1,b+1,-v);
	update(bit2,a,v*(a-1));
	update(bit2,b+1,-v*b);
}
long long query(long long bit[],int i){
	long long res = 0;
	for(;i>0;i-=i&(-i))res+=bit[i];
	return res;
}
long long query(int b){
	return query(bit1,b)*b - query(bit2,b);
}
long long query(int a,int b){
	return query(b) - query(a-1);
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
        	memset(bit1,0,sizeof bit1);
        	memset(bit2,0,sizeof bit2);
		while(m--){
			scanf("%d %d %d",&c,&p,&q);
			if(!c){scanf("%lld",&v);update(p,q,v);}
			else printf("%lld\n",query(p,q));
		}
	}
}
