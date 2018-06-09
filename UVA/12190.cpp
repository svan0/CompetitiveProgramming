#include <bits/stdc++.h>
using namespace std;
int cons2price(int cons){
    int price = 0;
    price+= max(0, min(cons,100) * 2), cons-=100;
    price+= max(0, min(cons,9900) * 3), cons-=9900;
    price+= max(0, min(cons,990000) * 5), cons-=990000;
    price+= max(0, cons*7);
    return price;
}
int price2cons(int price){
    int cons = 0;
    cons+= min(max(0,price/2),100); price-=2*100;
    cons+= min(max(0,price/3),9900); price-=3*9900;
    cons+= min(max(0,price/5),990000); price-=5*990000;
    cons+= max(0,price/7);
    return cons;
}
int main(){
    int a,b;
    while(cin>>a>>b, a|b){
        int total = price2cons(a);
        //cout<<total<<endl;
        int l = 0, r = total;
        int ans = 0;
        while(l<=r){
            int mid = (l+r)/2;
            int d = cons2price(total - mid) - cons2price(mid);
            //cout<<mid<<" "<<d<<endl;
            if(d < b)r = mid-1;
            else if(d > b)l = mid+1;
            else {ans = mid; break;}
        }
        cout<<cons2price(ans)<<endl;
    }
}
