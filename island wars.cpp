#include<bits/stdc++.h>
using namespace std;
int main(){
int n,q;
cin>>n>>q;
vector<pair<int,int>>arr(q);
for(int i=0;i<n;i++){
	cin>>arr[i].first>>arr[i].second;
	}
sort(arr,begin(),arr.end(),[](auto x,auto y){
return x.second>y.second;	
});
int last=-1;
int ans=0;
for(auto[a,b]:arr){
	if(a>last){
		last=b-1;
		ans++;
	}
	
}
cout<<ans<<endl;



return 0;
}
