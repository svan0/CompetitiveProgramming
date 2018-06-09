#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1011;
int dp[MAX_N][MAX_N];
int lst[MAX_N][MAX_N];
int mod[MAX_N][MAX_N];
int n;
queue<pair<int,int> > q;
int main()
{
   int t;cin>>t;
   while(t--){
        cin>>n;
        memset(dp,-1,sizeof dp);
        memset(mod,0,sizeof mod);
        q=queue<pair<int,int> >();
        for(int i=1;i<=9;i++){
            q.push({i%n,i});
            dp[i%n][i]=i;
            lst[i%n][i]=i;
        }
        while(!q.empty()){
            int sum=q.front().second;
            int rem=q.front().first;
            int nsum,nrem;
            q.pop();
            if(rem==0 && sum==n)break;
            for(int i=0;i<=9;i++){
                nsum=sum+i,nrem=(10*rem+i)%n;
                if(dp[nrem][nsum]!=-1 || nsum > n)continue;
                q.push({nrem,nsum});
                dp[nrem][nsum]=nsum;
                lst[nrem][nsum]=i;
                mod[nrem][nsum]=rem;
                }                
        }
        int m=0,s=n;
        stack<int> ans;
        for(int i=0;;i++){
            if(m==0 && s==0)break;
            ans.push(lst[m][s]);
            int m1=mod[m][s];
            int s1=dp[m][s]-lst[m][s];
            m=m1;s=s1;
        }
        while(!ans.empty()){cout<<ans.top();ans.pop();}
        cout<<endl;
   }
   return 0;
}


