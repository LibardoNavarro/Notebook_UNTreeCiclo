#include <bits/stdc++.h>
using namespace std;

#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;

int dirx[4] = {0, -1, 1, 0};
int diry[4] = {-1, 0, 0, 1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

vl p;
bitset<3010> bs;
void sieve(ll n){
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i<=n; i++){
        if (bs[i]){
            for (ll j=i*i; j<=n; j+=i) bs[j] = 0;
            p.push_back(i);
        }
    }
}

ll factores(ll n){
    ll num = 0;
    for (ll i = 0; i<sz(p) && p[i]*p[i]<=n; i++){
        if (n % p[i] == 0) num++;
        while(n % p[i] == 0){
            n /= p[i];
        }
    }
    if (n != 1) num++;
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n; cin >> n;
    if (n==1) cout << 0 << ln;
    else{
        sieve(n);
        ll ans = 0;
        for (int i = 1; i<=n; i++){
            ll fact = factores(i);
            if (fact == 2) ans++;
        }
        cout << ans << ln;
    }
    
    return 0;
}