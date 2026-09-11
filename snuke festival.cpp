#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	vector<long long>A(n),B(n),C(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<n;i++){
		cin>>B[i];
	}
	for(int i=0;i<n;i++){
		cin>>C[i];
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	long long ans=0;
	for(int i=0;i<n;i++){
		long long x=lower_bound(A.begin(),A.end(),B[i])-A.begin();
		long long y=C.end()-(upper_bound(C.begin(),C.end(),B[i]));
		ans+=x*y;
		
	}
	cout<<ans;
}
