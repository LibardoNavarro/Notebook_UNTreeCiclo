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

ll EulerPhi(ll N) {
    ll ans = N;
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
        if (N%p[i] == 0) ans -= ans/p[i];
        while (N%p[i] == 0) N /= p[i];
    }
    if (N != 1) ans -= ans/N;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve(1e7);

    while(true){
        ll n; cin >> n;
        if (!n) break;
        cout << EulerPhi(n) << "\n";
    }
    
    return 0;
}