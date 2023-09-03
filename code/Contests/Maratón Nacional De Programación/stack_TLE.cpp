#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
const int INF=1e9;
const ll INFL=1e18;
const int MOD=1e9+7;
const double EPS=1e-9;
int dirx[4]={0,-1,1,0};
int diry[4]={-1,0,0,1};
int dr[]={1,1,0,-1,-1,-1,0,1};
int dc[]={0,1,1,1,0,-1,-1,-1};
const string ABC="abcdefghijklmnopqrstuvwxyz";
const char ln='\n';


ll recur(ll l,ll r,vl& prefix, vector<vl>& memo ){
    if (memo[l][r]!=-1)return memo[l][r];

    if((l-r)==0){
        memo[l][r] =0;
        return 0;
    }
    if((r-l)==1){
        // if (l==0)return prefix[r]-prefix[l];
        memo[l][r] =prefix[r]-prefix[l-1];
        return prefix[r]-prefix[l-1];
    }


    ll mini=INFL;
    for(int i=l;i<r;i++){
        ll val = prefix[r]-prefix[l-1];
        mini = min(mini,val+recur(l,i,prefix,memo)+recur(i+1,r,prefix,memo));
    }
    memo[l][r]=mini;
    return mini;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        ll n1;cin>>n1;
        if (n1==0)break;
        vl vals(n1,0);
        for(int i=0;i<n1;i++)cin>>vals[i];
        vl prefix(n1+1,0);
        for(int i=1;i<=n1;i++){
            prefix[i]=prefix[i-1]+vals[i-1];
        }

        vector<vl> memo(1002,vl(1002,-1));
        ll res = recur(1,n1,prefix,memo);
        cout<<memo[1][n1]<<ln;



    }

}
