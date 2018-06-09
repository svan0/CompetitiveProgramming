#include <bits/stdc++.h>
using namespace std;
map<string,int> dp;
set<int> mexS;
int mex(){
    int res = 0;
    while(true){
        if(mexS.find(res) == mexS.end())return res;
        res++;
    }
}
int grundy(const string& s){
    if(dp.find(s)!=dp.end())return dp[s];
    mexS.clear();
    string next_s = s;
    if(s[0] == '.'){
        if(s[1] != 'O'){
            next_s[0] = 'O';
            mexS.insert(grundy(next_s));
        }
        if(s[1] != 'X'){
            next_s[0] = 'X';
            mexS.insert(grundy(next_s));
        }
    }
    next_s = s;
    if(s[s.length()-1] == '.'){
        if(s[s.length()-2] != 'O'){
            next_s[s.length()-1] = 'O';
            mexS.insert(grundy(next_s));
        }
        if(s[s.length()-2] != 'X'){
            next_s[s.length()-1] = 'X';
            mexS.insert(grundy(next_s));
        }
    }
    for(int i=1;i<s.length()-1;i++){
        next_s = s;
        if(s[i] == '.'){
            if(s[i-1] == 'X' && s[i+1] != 'O'){
                next_s[i] = 'O';
                mexS.insert(grundy(next_s));
            }
            if(s[i-1] == 'O' && s[i+1] != 'X'){
                next_s[i] = 'X';
                mexS.insert(grundy(next_s));
            }
            if(s[i-1] == '.'){
                if(s[i+1] != 'O'){
                    next_s[i] = 'O';
                    mexS.insert(grundy(next_s));
                }
                if(s[i+1] != 'X'){
                    next_s[i] = 'X';
                    mexS.insert(grundy(next_s));
                }
            }
        }
    }
    return mex();
}
int main(){



}
