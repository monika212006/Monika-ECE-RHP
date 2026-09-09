#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;cin>>n;
	int start=1;int end=10;
	for(int i=1;i<=n;i++){
		int curr;cin>>curr;
		if(!(curr>=start && curr<=end)){
			cout<<"No"<<endl;
			return;
		}
		if(i%10==0){
			start+=10;end+=10;
		}
	}
	cout<<"Yes"<<endl;
}
int main(){
	
	solve();
	
	return 0;
}
