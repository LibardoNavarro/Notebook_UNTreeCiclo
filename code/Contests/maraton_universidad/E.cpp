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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, k; cin >> n >> k;
    vi calificaciones(n+1);
    vi pesos(n+1);

    for (int i = 1; i<=n; i++) cin >> calificaciones[i];
    for (int i = 1; i<=n; i++) cin >> pesos[i];

    vector<vl> dp(n+1, vl(k+1, 0));

    for (ll i = 1; i<=n; i++){
        for (ll j = 1; j<=k; j++){
            if (j < pesos[i]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-pesos[i]] + calificaciones[i]);
            }
            
        }
    }

    cout << dp[n][k];

    return 0;
}