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

ll mod(ll a, ll m) {return ((a%m)+m)%m;}

struct matrix {
    int r, c; vector<vl> m;
    matrix(int r, int c, const vector<vl> &m) : r(r), c(c), m(m){}

    matrix operator * (const matrix &b){
        matrix ans(this->r, b.c, vector<vl>(this->r, vl(b.c, 0)));

        for (int i = 0; i<this->r; i++) {
            for (int k = 0; k<b.r; k++){
                if (m[i][k] == 0) continue;
                for (int j = 0; j<b.c; j++){
                    ans.m[i][j] += mod(m[i][k], MOD) * mod(b.m[k][j], MOD);
                    ans.m[i][j] = mod(ans.m[i][j], MOD);
                }
            }
        }
        return ans;
    }
};

matrix pow(matrix &b, ll p){
    matrix ans(b.r, b.c, vector<vl>(b.r, vl(b.c, 0)));
    for (int i = 0; i<b.r; i++) ans.m[i][i] = 1;
    while (p){
        if (p&1){
            ans = ans*b;
        }
        b = b*b;
        p >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;

    vi h(m+2);
    h[0] = 0;
    for (int i = 1; i<=m; i++) cin >> h[i];
    h[m+1] = n+1;
    sort(all(h));
    for (int i = 2; i<m+1; i++) {
        if (h[i]  - h[i-1] == 1) {cout << 0 << ln; return 0;}
    }
    vector<vl> fib = {{1LL, 1LL}, {1LL, 0LL}};
    vl fibo(1e6 +1);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i<=1e6; i++) fibo[i] = ((fibo[i-1]%MOD) + (fibo[i-2]%MOD)) % MOD;
    matrix f(2, 2, fib);
    ll ans = pow(f, h[1]).m[0][1];
    f.m = fib;
    for (int i = 2; i<m+2; i++){
        ll e = h[i] - h[i-1]-1;
        if (e<=1e6) ans = (ans * fibo[e]) % MOD;
        else{
            matrix temp = pow(f, e);
            ans = (ans * temp.m[0][1]) % MOD;
            f.m = fib;
        }
    }

    cout << ans << ln;

    return 0;
}