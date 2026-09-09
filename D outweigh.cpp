#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>A(n),B(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<n;i++) cin>>B[i];
	long long ta=0;long long ao=0;
	for(int i=0;i<n;i++){
		if(A[i]>B[i]){
			ta+=A[i]-B[i];
		}
		else if(A[i]<B[i]){
			ao+=B[i]-A[i];
		}
		
	}
	if(ta==0){
		cout<<"No"<<endl;
		return;
	}
	long long int w=(ao/ta)+2;
	vector<long long int>ans;
	for(int i=0;i<n;i++){
		if(A[i]<=B[i]){
			ans.push_back(1);
		}else{
			ans.push_back(w);
		}
		
	}
	cout<<"Yes"<<endl;
	for(long long int a:ans){
		cout<<a<<" ";
	}
	cout<<endl;}
	int main(){
		solve();
	
	return 0;
  }
