#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
int main(){
	int n; cin>>n;
	vector<int> loc(n,0);
	vector<ll> vp(n+1,0);
	for(int i=0;i<n;i++) cin>>loc[i];
	for(int i=1;i<=n;i++){
		int curr;
		cin>>curr;
		vp[i]=vp[i-1]+curr;
	}
	int q; cin>>q;
	while(q--){
		int l,r; cin>>l>>r;
		int lt=lower_bound(loc.begin(),loc.end(),l)-loc.begin();
		int rt=upper_bound(loc.begin(),loc.end(),r)-loc.begin();
		cout<<vp[rt]-vp[lt]<<endl;
	}
}
