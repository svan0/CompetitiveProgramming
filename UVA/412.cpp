#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> S;
double res;
int gcd(int a,int b){
    if(a>b)return gcd(b,a);
    if(a == 0)return b;
    return gcd(b%a,a);
}
int main(){
    while(cin>>N && N!=0){
        res = 0;
        S.clear();
        for(int i=0;i<N;i++){
            int a;
            cin>>a;
            S.push_back(a);
        }
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++)
                if(gcd(S[i],S[j]) == 1)res++;
        }
        if(res!=0)printf("%.6f\n",sqrt(6/(2*res/(N*(N-1)))));
        else cout<<"No estimate for this data set."<<endl;
    }

}
