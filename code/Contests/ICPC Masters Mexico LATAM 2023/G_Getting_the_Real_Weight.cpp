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
    ll n;cin>>n;
    vl res(0,0);
    if(n==1){
    cout<<0<<"\n";
    return 0;
    }
    for (ll i=1;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll act=pow(j,2)-pow(i,2);
            if(n==act){
                res.push_back(j);
            }else if(act>n){
                break;
            }
        }
    }
    sort(res.begin(), res.end());
    n=res.size();
    if (res.empty()){
        cout<<"0\n";
    }else{
    cout<<n<<"\n";
    for(ll i=0;i<n-1;i++)cout<<res[i]<<" ";
    cout<<res[n-1]<<"\n";
    return 0;
}}