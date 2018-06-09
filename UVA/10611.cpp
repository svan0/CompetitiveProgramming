#include <bits/stdc++.h>
using namespace std;
int n,q,qr;
int arr[50505];
int u_bound(int val){
    int l = 0, r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]>val)r = mid-1;
        else l = mid + 1;
    }
    if(r==n-1)cout<<"X";
    else cout<<arr[r+1];
}
int l_bound(int val){
    int l = 0, r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]<val)l = mid + 1;
        else r = mid - 1;
    }
    if(l==0)cout<<"X";
    else cout<<arr[l-1];
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    cin>>q;
    while(q--){
        cin>>qr;
        l_bound(qr);
        cout<<" ";
        u_bound(qr);
        cout<<endl;
    }
}
