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
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        map<int, int> m;
        for (int i = 0; i<n; i++){int a; cin >> a; m[a]++;}
        map<int, int> m1;
        int ans = 0;
        for (auto par: m){
            if (par.first > n) continue;
            for (ll i = par.first; i<=n; i+=par.first){
                m1[i] += par.second;
                ans = max(ans, m1[i]);
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}