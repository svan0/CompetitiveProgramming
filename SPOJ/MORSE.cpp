#include <iostream>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
 
const int MAXS = 1001001;
const int MAXC = 2;
const string MORSE[26] = {
	".-", "-...","-.-.","-..", 
	".","..-.","--.","....", 
	"..",".---","-.-",".-..", 
	"--","-.","---",".--.", 
	"--.-",".-.","...","-", 
	"..-","...-",".--","-..-", 
	"-.--","--.."
};
int T;
string text;
int q;
string words[10101],S;
bool found[10101][10101];
int dp[10101];
 
int g[MAXS][MAXC];
int f[MAXS];
set<int> out[MAXS];
 
int char_to_int(char c){
	return int(c=='.');
}
 
int build_machine(){
	memset(g,-1,sizeof g);
	for(int i=0;i<MAXS;i++)out[i].clear();
	memset(f,-1,sizeof f);
	//Building Trie
	int states=1;
	for(int i=0;i<q;i++){
		const string &word=words[i];
		int current_state=0;
		for(int j=0;j<word.length();j++){
			if(g[current_state][char_to_int(word[j])]==-1)
				g[current_state][char_to_int(word[j])]=states++;
			current_state=g[current_state][char_to_int(word[j])];
		}
		out[current_state].insert(i);
	}
	//Building Automaton
	for(int ch=0;ch<MAXC;ch++){
		if(g[0][ch]==-1)g[0][ch]=0;
	}
	queue<int> Q;
	for(int ch=0;ch<MAXC;ch++){
		if(g[0][ch]!=0){
			f[g[0][ch]]=0;
			Q.push(g[0][ch]);
		}
	}
	while(!Q.empty()){
		int current_state=Q.front();
		Q.pop();
		for(int ch=0;ch<MAXC;ch++){
			if(g[current_state][ch]!=-1){
				int prev_state=f[current_state];
				while(g[prev_state][ch]==-1)prev_state=f[prev_state];
				f[g[current_state][ch]]=g[prev_state][ch];
				out[g[current_state][ch]].insert(out[f[g[current_state][ch]]].begin(),out[f[g[current_state][ch]]].end());
				Q.push(g[current_state][ch]);
			}
		}
	}
	return states;
}
int find_next_state(int current_state,char c){
	int ans=current_state;
	int ch=char_to_int(c);
	while(g[ans][ch]==-1)ans=f[ans];
	return g[ans][ch];
}
void searchWords(){
	build_machine();
	int current_state = 0;
	for(int i=0;i<text.length();i++){
		current_state=find_next_state(current_state,text[i]);
		if(out[current_state].empty())continue;
		for(int j=0;j<q;j++){
			if(out[current_state].find(j)!=out[current_state].end()){
				found[i][j]=true;
				//cout<<"found word "<<j<<" end at "<<i<<endl;
			}
		}
	}
}
void solve(){
	memset(found,0,sizeof found);
	memset(dp,0,sizeof dp);
	cin>>text;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>S;
		words[i]="";
		for(int j=0;j<S.length();j++)words[i]+=MORSE[S[j]-'A'];
	}
	searchWords();
	for(int i=0;i<text.length();i++)
		for(int j=0;j<q;j++){
			if(found[i][j]){
				if(i-words[j].length()+1>0)dp[i]+=dp[i-words[j].length()];
				else dp[i]+=1;
			}
		}
	cout<<dp[text.length()-1]<<endl;
			
}
int main(){
	cin>>T;
	while(T--)solve();
}
