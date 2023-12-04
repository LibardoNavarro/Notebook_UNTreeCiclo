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
void sieve(int n){
    vector<bool> bs(n+1, true);
    bs[0] = bs[1] = 0;
    for (int i = 2; i<=n; i++){
        if (bs[i]){
            for (ll j=i*1LL*i*1LL; j<=n; j+=i) bs[j] = 0;
            p.push_back(i);
        }
    }
}

bool factores(int n, set<int> &usados){
    vi fact;
    for (int i = 0; (i < sz(p)) && (p[i]*p[i] <= n); ++i){
        if (n % p[i] == 0) {
            fact.push_back(p[i]);
            if (usados.count(p[i])) return true;
            else usados.insert(p[i]);
        }
        while(n % p[i] == 0){
            n /= p[i];
        }
    }
    if (n != 1) {
        fact.push_back(n);
        if (usados.count(n)) return true;
        else usados.insert(n);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    sieve(1e5);

    int t; cin >> t;

    while (t--){
        set<int> usados;
        int n; cin >> n;
        bool b = false;
        vi v(n);
        for (int i = 0; i<n; i++) cin >> v[i];
        for (int a : v){
            if (a == 1 || factores(a, usados)){
                cout << "YES\n";
                b = true;
                break;
            }
        }
        if (!b) cout << "NO\n";
    }

    return 0;
}