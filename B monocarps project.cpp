#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long x,y,k;
	cin>>x>>y>>k;
	long long ctr=0;
	long long ans=0;
	while(ctr<k){
		int rem=(y+ctr)%(x+ctr);
		if(rem==y-x) break;
		ans+=rem;
		ctr++;
	}
	if(k>ctr){
		ans=ans+(k-ctr)*(y-x);
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
