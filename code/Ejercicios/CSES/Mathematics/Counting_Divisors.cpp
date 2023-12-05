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
 
vi p;
void sieve(ll n){
    vector<bool> bs(n+1, 1);
    bs[0] = bs[1] = 0;
    for (ll i = 2; i<=n; ++i) if (bs[i]) {
        for (ll j = i*i; j<=n; j+=i) bs[j] = 0;
        p.push_back(i);
    }
}
 
int numDiv(int n){
    int ans = 1;
    for (int i = 0; p[i]*p[i]<=n && i<sz(p); i++){
        int e = 1;
        while (n % p[i] == 0){
            n /= p[i];
            ++e;
        }
        ans *= e;
    }
    if (n != 1) ans *= 2;
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    vi p;
    sieve(1e6);
    int n; cin >> n;
    while (n--){
        int x; cin >> x;
        cout << numDiv(x) << ln;
    }
 
    return 0;
}