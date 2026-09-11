#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	map<int,int>m;
	for(int i=1;i<=n;i++){
		int curr;cin>>curr;
		m[curr]++;
	}
	int ans=0;
	for(auto[val,cnt]:m){
		if(cnt&1){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
