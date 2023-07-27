#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef vector<long long> vl;

void bucle_invariable(string c){
    ll n=c.size();string c2=c+c;
    ll balance=0;ll index=0;
    ll ultima=0;
    ll diferencia=0;
    for (ll i=0;i<n;i++){
        char actual=c[i];
        balance+= actual=='('?1:-1;
        if (!balance){
            if (!diferencia){
                diferencia=index-ultima;
            }else if(index-ultima!=diferencia){
                cout<<c2.substr(index,n)<<"\n";
                return;
            }
            ultima=index;
            index=i+1;
        }
    }
    if (c!=c2.substr(ultima,n)){
        cout<<c2.substr(ultima,n)<<"\n";
    }else{
        cout<<"no\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c;cin>>c;bucle_invariable(c);
    return 0;
}

