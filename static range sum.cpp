#include<iostream>
#include<vector>
#include<numeric>
#define ll long long int
using namespace std;
void solve(){
    int N,Q; cin>>N>>Q;
    vector<ll> p(N+1,0);
    for(int i=0;i<N;i++) {
        int arr; cin>>arr;
        p[i] = p[i-1] + arr;
    }
    while(Q--) {
        int l, r; cin>>l>>r;
        cout<<p[r] - p[l - 1]<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}
