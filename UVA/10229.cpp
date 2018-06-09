#include <bits/stdc++.h>
using namespace std;
long long int n,m,mod;
struct Matrix{
    long long int m[2][2];
};
Matrix mul(Matrix a,Matrix b){
    Matrix c;
    c.m[0][0] = c.m[0][1] = c.m[1][0] = c.m[1][1] = 0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                c.m[i][j]= (c.m[i][j] + a.m[i][k]*b.m[k][j])%mod;
    return c;
}
Matrix pow(Matrix a,long long int n){
    if(n==1)return a;
    Matrix c = pow(a,n/2);
    c = mul(c,c);
    if(n%2==1)c = mul(c,a);
    return c;
}
int main(){
    Matrix f;
    f.m[0][0] = f.m[0][1] = f.m[1][0] = 1;
    f.m[1][1] = 0;
    while(cin>>n>>m){
        mod = (1LL<<m);
        if(n<=1){cout<<n<<endl;continue;}
        Matrix r = pow(f,n);
        cout<<r.m[0][1]<<endl;
    }
}
