#include <bits/stdc++.h>
using namespace std;
int n,xl,yl,xr,yu, xxl,yyl,xxr,yyu,res_xl,res_yl,res_xr,res_yu;
int main(){
    cin>>n;
    while(n--){
        cin>>xl>>yl>>xr>>yu;
        cin>>xxl>>yyl>>xxr>>yyu;
        res_xl = max(xl,xxl);
        res_yl = max(yl,yyl);

        res_xr = min(xr,xxr);
        res_yu = min(yu,yyu);

        if(res_xl >= res_xr)cout<<"No Overlap"<<endl;
        else if(res_yl >= res_yu)cout<<"No Overlap"<<endl;
        else cout<<res_xl<<" "<<res_yl<<" "<<res_xr<<" "<<res_yu<<endl;
        if(n>0)cout<<endl;

    }
}
