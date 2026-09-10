#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long n;cin>>n;
	long long base=0;
	int mini=2e9;
	vector<pair<int,int>>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
		base+=arr[i].first;
		mini=min(mini,arr[i].first);
	}
	sort(arr.begin(),arr.end(),[](const pair<int,int>& a,const pair<int,int>& b){
		return a.first-a.second>b.first-b.second;
	});
	long long ans=base;
	for(int i=1;i<=n;i++){
		base-=arr[i-1].first;
		base+=arr[i-1].second;
		long long curr=base+((n-i)>=i?0:mini*(i-(n-i)));
		ans=min(ans,curr);
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
