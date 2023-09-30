#include <bits/stdc++.h>
using namespace std;

#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
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

const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

ll bellman_ford(vector<vector<pair<int, ll>>> &adj, int s, int t, int n, vi &d1, vi &d2){
    vl d(n+1, INFL);
    d[s] = 0LL;
    for (int i = 0; i<n-1; i++){
        bool cambio = false;
        for (int u = 1; u<=n; u++){
            if (d[u] == INFL) continue;
            for (auto &[v, w] : adj[u]){
                if (d[v] > d[u] + w){
                    cambio = true;
                    d[v] = d[u] + w;
                }
            }
        }
        if (!cambio) return d[t];
    }
    for (int u = 1; u<=n; u++){
        if (d[u] == INFL) continue;
        for (auto &[v, w] : adj[u]){
            if (d[v] > d[u] + w && d1[v] && d2[v]) return 1;
        }
    }
    
    return d[t];
}

void dfs(vector<vector<pair<int, ll>>> &adj, int u, vi &d){
    d[u] = 1;
    for (auto [v, w] : adj[u]){
        if (!d[v]) dfs(adj, v, d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n+1), adj1(n+1);

    for (int i = 0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, -c});
        adj1[b].push_back({a, -c});
    }

    vi d1(n+1, 0), d2(n+1, 0);
    dfs(adj, 1, d1); dfs(adj1, n, d2);

    cout << -1LL * bellman_ford(adj, 1, n, n, d1, d2) << ln;

    return 0;
}