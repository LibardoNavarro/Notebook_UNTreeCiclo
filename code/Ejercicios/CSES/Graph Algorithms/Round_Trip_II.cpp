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

int dfs(vector<vi> &adj, vi &vis, vi&p, int u){
    vis[u] = 1;

    for (int v : adj[u]){
        if (!vis[v]) {
            p[v] = u;
            int ans = dfs(adj, vis, p, v);
            if (ans) return ans;
        }
        else if (vis[v] == 1){
            p[v] = u;
            return v;
        }
    }

    vis[u] = 2;
    return 0;
}

void path(vi &p, int s, int t, vi &ans, int c){
    if (s == t && c !=0) {ans.push_back(s) ;return;}
    path(p, s, p[t], ans, c+1);
    ans.push_back(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;
    vector<vi> adj(n+1);

    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vi vis(n+1, 0), p(n+1, -1);
    int v = 0;
    for (int i = 1; i<=n; i++){
        if (!vis[i]){
            v = dfs(adj, vis, p, i);
            if (v) break;
        }
    }

    if (v) {
        vi ans;
        path(p, v, v, ans, 0);
        cout << sz(ans) << ln;
        for (int u : ans) cout << u << " ";
    }
    else cout << "IMPOSSIBLE\n";

    return 0;
}