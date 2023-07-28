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
bitset<10001001> bs;
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

vl factores(ll n){
    vl fact;
    for (ll i = 0; i<sz(p) && p[i]*p[i]<=n; i++){
        while(n % p[i] == 0){
            fact.push_back(p[i]);
            n /= p[i];
        }
    }
    if (n != 1) fact.push_back(n);
    return fact;
}

bool isPrime(ll N) {
    if (N < 10001001) return bs[N];
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        if (N%p[i] == 0)
            return false;
    return true;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve(10001000);
    // cout << p.back() << "\n";

    while (true){
        ll n; cin >> n;
        if (!n) break;
        n = abs(n);
        if (isPrime(n)) {cout << -1 << "\n"; continue;}
        vl ans = factores(n);
        if (ans[0] == ans[sz(ans)-1]) cout << -1 << "\n";
        else cout << ans.back() << "\n";
    }
    
    return 0;
}