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
    ll n,q;cin>>n>>q;
    map<string,ll> maps;
    for(int i=0;i<n;i++){
        string name;cin>>name;
        maps[name]=i;
    }

    for(int i=0;i<q;i++){
        string name1,name2;cin>>name1>>name2;
        cout<<abs(maps[name1]-maps[name2])-1<<ln;
    }
}