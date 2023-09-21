#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const char ln = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vl> res(26,vl(26,0));
    for(int i=0;i<26;i++)res[1][i]=1;
    for(int i=0;i<26;i++)res[i][1]=1;
    for(int i=2;i<26;i++){
		for(int j=2;j<26;j++){
            res[i][j]=res[i-1][j]+res[i][j-1];
		}
	}
    ll t;cin>>t;
    while(t--){
        ll c,r;cin>>c>>r;
        cout<<res[c][r]<<ln;
    }
}