#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>arr(n);
	vector<int>zi;
	for(unsigned int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==0){
			zi.push_back(i);
		}
	}
	if(zi.size()==1){
		cout<<"NO"<<endl;
		return;
	}
	string s(n,'C');
	if(zi.size()>0){
		int fzindx=zi[0];
		s[fzindx]='B';
		for(unsigned int i=1;i<zi.size();i++){
			s[zi[i]]='A';
		}
	}
	cout<<"YES"<<endl<<s<<endl;
	
	
}
int main(){
	int q;cin>>q;
	while(q--){
		solve();
	}
	return 0;
}
