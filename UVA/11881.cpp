#include <bits/stdc++.h>
using namespace std;
int T;
int cf[11];
double NPV(double irr){
    double res = 0.0;
    for(int i=0;i<=T;i++)res+=cf[i]/pow(1.0 + irr, i);
    return res;
}
int main(){
    while(cin>>T && T){
        for(int i=0;i<=T;i++)cin>>cf[i];
        double l = -1.0, r = 1e9;
        double mid;
        for(int i=0;i<200;i++){
            mid = (l+r)/2.0;
            if(NPV(mid)<0)r = mid;
            else l = mid;
        }
        printf("%.2f\n",mid);
    }
}
