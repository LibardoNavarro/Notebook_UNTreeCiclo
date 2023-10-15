#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const double EPS  = 1e-9;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20) << fixed;
    // cout<<('a'-'y')<<ln;
    ll n1;cin>>n1;
    string wor1;cin>>wor1;
    string wor2;cin>>wor2;

    ll res =0;
    for(int i=0;i<n1;i++){
        int x1,x2;
        x1=abs(tolower(max(wor1[i], wor2[i]))-tolower(min(wor2[i],wor1[i])))    ;
        x2=abs(-'a'+tolower(min(wor1[i],wor2[i]))+'z'-tolower(max(wor2[i], wor1[i])))+1;
        // cout<<min(x2,x1)<<"\n";
        res+=min(x1,x2);
    }
cout<<res<<"\n";
    return 0;
}