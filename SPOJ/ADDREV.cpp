#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string Str(int n);
int Int(string s);
int main() {

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        string sA=Str(a),sB=Str(b);
        reverse(sA.begin(),sA.end());
        reverse(sB.begin(),sB.end());
        int R=Int(sA)+Int(sB);
        while(R%10==0)R/=10;
        string r=Str(R);
        reverse(r.begin(),r.end());
        cout<<r<<endl;
    }
	return 0;
}
string Str(int n)
{
    stringstream ss;
    ss<<n;
    return ss.str();
}
int Int(string s)
{
    int n;
    istringstream(s)>>n;
    return n;
}


