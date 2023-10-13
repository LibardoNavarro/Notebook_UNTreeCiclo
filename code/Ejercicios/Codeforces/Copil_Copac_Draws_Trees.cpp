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

void dfs(vector<vi> &adj, map<ii, int> &index, vi &dp, vi &id, int u){
    for (int v : adj[u]){
        if (index[{u, v}] > id[u] && !dp[v]){
            dp[v] = dp[u];
            id[v] = index[{u, v}];
            dfs(adj, index, dp, id, v);
        }
        else if (index[{u, v}] < id[u] && !dp[v]){
            dp[v] = dp[u]+1;
            id[v] = index[{u, v}];
            dfs(adj, index, dp, id, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        vector<vi> adj(n+1);
        vi dp(n+1, 0);
        dp[1] = 1;
        map<ii, int> index;
        vi id(n+1);
        id[1] = 0;
        for (int i = 0; i<n-1; i++){
            int u, v; cin >> u >> v;
            index[{u, v}] = i+1;
            index[{v, u}] = i+1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj, index, dp, id, 1);
        int ans = -INF;
        for (int i = 1; i<=n; i++) ans = max(ans, dp[i]);
        cout << ans << ln;
    }

    return 0;
}