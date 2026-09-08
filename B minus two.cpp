#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;cin>>n;
	int od=0;
	int eoq=0;
	int eeq=0;
	for(int i=0;i<n;i++){
		int curr;cin>>curr;
		if(curr&1){
			od++;
		}
		else {
			int q=curr/2;
			if(q&1) eoq++;
			
			else eeq++;
		}
		}
		int maxi=max(od,max(eoq,eeq));
		cout<<maxi<<endl;
	
}
int main(){
	int q;cin>>q;
	while(q--){
		solve();
	}
	return 0;
}
