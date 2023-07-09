#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
const char ln = '\n';

bool fsort(pair<ll,ll> a, pair<ll,ll> b) {
    if (a.first>b.first){
        return true;
    }else if(a.first<b.first){
        return false;
    }else{
        if (a.second<b.second){
            return true;
        }else{
            return false;
        }
    }
}

bool iguales(pair<ll,ll> a, pair<ll,ll> b){
    if (a.first==b.first && a.second==b.second){
        return true;
    }else{
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> tems;
    for (int i =0;i<n;i++){
        ll p,t;cin>>p>>t;
        pair<ll,ll> tem = {p,t};
        tems.push_back(tem);
    }

    sort(tems.begin(), tems.end(), fsort);
    // for (pair elemento : tems) {
    //     cout << elemento.first << " "<<elemento.second<<ln;
    // }

    ll cont=1;
    ll conE=1;
    pair<ll,ll> temp = tems[0];
    pair<ll,ll> add = {-1,-1};
    tems.push_back(add);
    for (int e =1;e<=n;e++){
        if (iguales(temp,tems[e])){
            conE++;
        }else if(cont>=m){
            cout<<conE<<ln;
            break;
        }else{
            conE=1;
        }
        cont++;
        temp=tems[e];
    }


    
}