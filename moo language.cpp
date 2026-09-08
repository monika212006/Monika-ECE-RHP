#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;cin>>n;
	int k;cin>>k;
	string s;cin>>s;
	int N=n/k;
	vector<bool>own(N,false);
	for(unsigned int i=0;i<s.size();i++){
		
		if(s[i]=='0'){
			int farmindx=i/k;
			own[farmindx]=true;
		}
		
		
	}
	int count=0;
	for(int i=0;i<N;i++){
		if(!own[i]){
			count++;
		}
	}
	cout<<count<<endl;
	
}
int main(){
	int q;cin>>q;
	while(q--){
		solve();
	}
	return 0;
}
