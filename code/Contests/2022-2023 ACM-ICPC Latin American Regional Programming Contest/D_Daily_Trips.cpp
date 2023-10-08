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
    ll n,h,w;cin>>n>>h>>w;
    while(n--){
        char n1,n2;cin>>n1>>n2;
        bool o1,o2;o1=false;o2=false;
        if(n1=='Y' || w==0){
            h--;
            w++;
            o1=true;
        }

        if(n2=='Y' || h==0){
            w--;
            h++;
            o2=true;
        }

        cout<<(o1?"Y":"N")<<" "<<(o2?"Y":"N")<<ln;

    }
}