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
    ll n0;cin>>n0;
    set<vector<vl>> mapa;
    while(n0--){
        vector<vl> puntos;
        ll minx=0;
        ll miny=LONG_LONG_MAX;
        ll n1;cin>>n1;
        for(int i=0;i<n1;i++){
            ll x,y;cin>>x>>y;
            vl punto={x,y};
            puntos.push_back(punto);
        }

        sort(puntos.begin(),puntos.end());
        vl pun0 = {puntos[0][0],puntos[0][1]};
        for(int i=0;i<puntos.size();i++){
            puntos[i][0]-=pun0[0];
            puntos[i][1]-=pun0[1];
        }
        mapa.insert(puntos);
    }

    cout<<mapa.size()<<ln;
    
}