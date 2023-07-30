#include <bits/stdc++.h>
using namespace std;

#define sz(arr) ((int) arr.size())
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

vl p;
bitset<10000010> bs;
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

ll numDiv(ll n){
    ll num = 1;
    for (ll i = 0; i<sz(p) && p[i]*p[i]<=n; i++){
        ll e = 1;
        while(n % p[i] == 0){
            e++;
            n /= p[i];
        }
        num *= e;
    }
    if (n != 1) num*=2;
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve(1e7);

    int n; cin >> n;

    while(n--){
        ll l, u; cin >> l >> u;
        pair<ll, ll> ans = {0LL, 0LL};
        for (ll i = l; i<=u; i++){
            ll a = numDiv(i);
            if (a>ans.second) ans = {i, a};
        }
        cout << "Between " << l << " and " << u << ", " << ans.first << " has a maximum of " << ans.second << " divisors." << "\n";
    }
    
    return 0;
}