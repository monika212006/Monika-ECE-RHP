#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;cin>>n;
	int m;cin>>m;
	vector<int> cnt(m+1,0);
	for(int i=1;i<n+1;i++){
		int curr;cin>>curr;
		cnt[curr]++;
	}
	vector <int>psum(m+1,0);
	for(int i=1;i<m+1;i++){
		psum[i]=psum[i-1]+cnt[i];
	}
	int ans=0;
	for(int i=1;i<m+1;i++){
		int carr=psum[m]-psum[i-1];
		if(2*i<=m){
			carr+=cnt[2*i];
		}
		ans=max(ans,carr);
		
	}
	cout<<ans<<endl;
}
int main(){
	int q;cin>>q;
	while(q--){
		solve();
	}
	return 0;
}
