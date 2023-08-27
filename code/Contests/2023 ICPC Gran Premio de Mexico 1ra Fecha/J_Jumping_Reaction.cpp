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
const int i2 = 500000004;

ll mod(ll a, ll m) {return ((a%m)+m)%m;}

ll modS(ll a, ll b, ll m) {return mod(mod(a, m) + mod(b, m), m);}
ll modR(ll a, ll b, ll m) {return mod(mod(a, m) - mod(b, m), m);}
ll modM(ll a, ll b, ll m) {return mod(mod(a, m) * mod(b, m), m);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vl v(n);
    vl sumas(n+1, 0);
    vl cuadrados(n+1, 0);
    for (int i = 0; i<n; i++){
        cin >> v[i];
        sumas[i+1] = modS(sumas[i], v[i], MOD);
        cuadrados[i+1] = modS(cuadrados[i], modM(v[i], v[i], MOD), MOD); 
    }
    for (int i = 0; i<q; i++){
        int l, r; cin >> l >> r;
        ll ans = modR(modM(sumas[r]-sumas[l-1], sumas[r]-sumas[l-1], MOD), cuadrados[r]-cuadrados[l-1],MOD);
        ans = modM(ans, i2, MOD);
        cout << ans << "\n";
    }
    
    return 0;
}