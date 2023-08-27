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

bitset<10000010> bs;
vl p;
void sieve(ll n) {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <=n; ++i) if (bs[i]) {
        for (ll j = i*i; j <= n; j += i) bs[j] = 0;
        p.push_back(i);
    }
}

bool isPrime(ll N) {
    if (N <= 10000000) return bs[N];
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        if (N%p[i] == 0)
            return false;
    return true;
}

ll solve(ll N) {
    ll ans = 0;
    map<ll, bool> usado;
    for (int i = 0; (i < (int)p.size()) && (p[i] <= N); ++i){
        ll num = p[i];
        usado[p[i]] = 1;
        while (N%num == 0) {
            N /= num;
            usado[num] = 1;
            ans++;
            num *= p[i];
        }
    }
    if (usado[N]) return ans;
    else if(isPrime(N)) return ans + 1LL;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve(10000000);

    ll n; cin >> n;
    if (isPrime(n)) cout << 1 << "\n";
    else cout << (n == 1LL ? 0 : solve(n)) << "\n";

    return 0;
}