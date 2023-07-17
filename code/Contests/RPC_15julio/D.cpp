#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
const char ln = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll s,n;cin>>s>>n;
    s++;

    vector<vl> peces(101,vl(101,0));

    for (int i = 0; i<n; i++){
        ll x,y;cin>>x>>y;
        peces[x][y]=1;
    }

    // for (int i =1;i<=10;i++){
    //     for (int j =1;j<=10;j++){
    //         cout<<peces[i][j]<<" ";
    //     }
    //     cout<<ln;
    // }

    vector<vl> prefix2d(102,vl(102,0));

    for (int i =1;i<=101;i++){
        for (int j =1;j<=101;j++){
            prefix2d[i][j]=peces[i-1][j-1]+prefix2d[i-1][j]+prefix2d[i][j-1]-prefix2d[i-1][j-1];
        }
    }
    // cout<<"========================="<<ln;

    // for (int i =1;i<=10;i++){
    //     for (int j =1;j<=10;j++){
    //         cout<<prefix2d[i][j]<<" ";
    //     }
    //     cout<<ln;
    // }

    ll res = 0;
    for (int i =s;i<=101;i++){
        for (int j =s;j<=101;j++){
            ll op=prefix2d[i][j]-prefix2d[i-s][j]-prefix2d[i][j-s]+prefix2d[i-s][j-s];
            res = max(res,op);
        }
    }

    cout<<res<<ln;
}