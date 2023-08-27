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
    ll r,c,k;cin>>r>>c>>k;
    vl heig(r+1,0);
    for(ll i=0;i<c;i++){
        ll num;cin>>num;
        heig[num]+=1;
    }
    sort(heig.begin(), heig.end());
    ll res=0;
    if(r<=k){
        for(ll i=0;i<r+1;i++){
            res+=heig[i];
        }
    }else{
        for(ll i=0;i<k;i++){
            res+=heig[r-i];
        }
    }
    cout<<res<<"\n";
    return 0;
}