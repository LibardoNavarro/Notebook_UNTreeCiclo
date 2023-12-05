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

vi factores(int n){
    vi fact;
    for (int i = 0; p[i]*p[i]<=n && i<=sz(p); ++i){
        while (n % p[i] == 0){
            n /= p[i];
            fact.push_back(p[i]);
        }
    }
    if (n != 1) fact.push_back(n);
    return fact;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    sieve(1e6);

    map<int, int> m;
    map<int, vi> divisores;
    int n; cin >> n;
    for (int y = 0; y<n; ++y){
        int x; cin >> x;
        if (!divisores[x].empty()){
            vi divs = divisores[x];
            for (int w : divs) ++m[w];
        }
        else{
            vi fact = factores(x);
            int n1 = sz(fact);
            set<int> esta;
            for(int b=0;b<(1<<n1);b++){
                vi subset;
                for(int i=0;i<n1;i++)if(b&(1<<i))subset.push_back(i);
                int num = 1;
                for (int i : subset) num *= fact[i];
                if (!esta.count(num)) ++m[num];
                esta.insert(num);
            }
            for (int w : esta) divisores[x].push_back(w);
        }
    }
    int ans = 1;
    for (auto par : m){
        if (par.second > 1) ans = max(ans, par.first);
    }

    cout << ans << ln;

    return 0;
}