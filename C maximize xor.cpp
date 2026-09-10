#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x,y,rx=0,ry=0;
	cin>>x>>y;
	int sum=x+y;
	cout<<sum<<" ";
	
	
	for(int sh=30;sh>=0;sh--){
		if((sum&(1<<sh))!=0){
			if((rx|(1<<sh))<=x){
				rx=rx|(1<<sh);
			}else ry=ry|(1<<sh);
			
		}
	}
	cout<<x-rx<<endl;
		
	
}
int main(){
	int q;cin>>q;
	while(q--){
		solve();
	}
	return 0;
}
