#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int q;cin>>q;
	vector<int>pos(n+1,0);
	for(int i=1;i<=n;i++){
		int curr;cin>>curr;
		pos[curr]=i;
	}
	int nextpos=n+1;
	while(q--){
		int a;cin>>a;
		pos[a]=nextpos;
		nextpos++;
	}
	vector<pair<int,int>>arr;
	for(int val=1;val<=n;val++){
	arr.push_back(make_pair(pos[val],val));
	
	}
	sort(arr.begin(),arr.end());
	for(auto[pas,val]:arr){
		cout<<val<<" ";
	}
	cout<<endl;
	return 0;
}
