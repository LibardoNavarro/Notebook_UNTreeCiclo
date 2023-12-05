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

void path(vi &p, int s, int t, vi &ans){
    if (s == t) {ans.push_back(s); return;}
    path(p, s, p[t], ans);
    ans.push_back(t);
}

void dfs(vector<vi> &adj, vector<bool> &vis, int u){
    vis[u] = true;
    for (int v : adj[u]){
        if (!vis[v]) dfs(adj, vis, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;

    vector<vi> adj(n+1);
    vi g(n+1, 0);
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        ++g[b];
    }
    vi d(n+1, -1), p(n+1, -1);
    queue<int> q;
    for (int i = 0; i<n; i++){
        if (!g[i]) {q.push(i); d[i]=0;}
    }
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u]){
            if (d[v] < d[u] + 1){
                d[v] = d[u] + 1;
                p[v] = u;
            }
            --g[v];
            if (!g[v]) q.push(v);
        }
    }

    vector<bool> vis(n+1, false);
    dfs(adj, vis, 1);
    if (!vis[n]) cout << "IMPOSSIBLE\n";
    else{
        vi ans;
        path(p, 1, n, ans);
        cout << sz(ans) << ln;
        for (int i : ans) cout << i << " ";
    }

    return 0;
}