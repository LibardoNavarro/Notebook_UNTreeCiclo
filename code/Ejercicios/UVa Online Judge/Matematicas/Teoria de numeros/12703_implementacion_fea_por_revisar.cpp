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

vector<pair<ll, ll>> factores(ll n){
    vector<pair<ll, ll>> fact;
    for (ll i = 0; i<sz(p) && p[i]*p[i]<=n; i++){
        ll e = 0;
        while(n % p[i] == 0){
            e++;
            n /= p[i];
        }
        if (e) fact.push_back(make_pair(p[i], e));
    }
    if (n != 1) fact.push_back(make_pair(n, 1));;
    return fact;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve(1e7);

    int t; cin >> t;

    while (t--){
        ll n, a, b; cin >> n >> a >> b;
        vector<vector<pair<ll, ll>>> fib(n+1);
        fib[2] = {make_pair(a, 1LL), make_pair(b, 1LL)};
        if (n>2) fib[3] = {make_pair(a, 1LL), make_pair(b, 2LL)};
        for (int i = 4; i<=n; i++){
            vector<pair<ll, ll>> l(2);
            for (int j = 0; j<2; j++){
                l[j] = {fib[i-1][j].first, fib[i-1][j].second + fib[i-2][j].second};
            }
            fib[i] = l;
        }
        for (pair<ll, ll> i : fib[n]){
            cout << i.first << " " << i.second << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}