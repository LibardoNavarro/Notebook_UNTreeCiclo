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

    int n, q; cin >> n >> q;

    vector<string> v(n);

    for (int i = 0; i<n; i++) cin >> v[i];
    sort(all(v));
    for (int i = 0; i<q; i++){
        string a, b; cin >> a >> b;
        int ans1 = lower_bound(all(v), a) - v.begin();
        int ans2 = upper_bound(all(v), b) - v.begin();
        cout << ans2 - ans1 << ln;
    }

    return 0;
}