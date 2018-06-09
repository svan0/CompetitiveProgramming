#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;

int main()
{
    vector<long long int> primes;
    primes.push_back(2);
    primes.push_back(3);
    for(long long int i=5;i<32000;i+=2)
    {
        int j=0;
        bool prime=true;
        long long int SR=sqrt(i);
        while(primes[j]<=SR)
        {
            if(i%primes[j]==0){prime=false;break;}
            j++;
        }
        if(prime)primes.push_back(i);
    }


    int n;
    cin>>n;
    for(int k=0;k<n;k++)
    {
        long long int a,b;
        cin>>a>>b;
        if(a<=2)cout<<2<<endl;
        if(a%2==0)a+=1;
        if(a==1)a=3;
        for(long long int i=a;i<=b;i+=2)
        {
            bool prime=true;
            long long int SQ=sqrt(i);
            for(int j=0;j<primes.size() && primes[j]<=SQ;j++)
                if(i%primes[j]==0){prime=false;break;}

            if(prime)cout<<i<<endl;
        }
        cout<<endl;
    }


}

