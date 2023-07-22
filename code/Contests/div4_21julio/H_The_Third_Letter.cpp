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

bool ans = true;

void dfs(vector<vector<pair<ll, ll>>> &graph, vl &pos, ll v, vi &vis){
    vis[v] = 1;
    for (int i = 0; i<sz(graph[v]); i++){
        ll vec = graph[v][i].first, d = graph[v][i].second;
        if (!vis[vec]) {
            pos[vec] = pos[v] + d;
            dfs(graph, pos, vec, vis);
        }
        else{
            if (pos[vec] != pos[v] + d) {ans = false;}
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--){
        ans = true;
        int n, m; cin >> n >> m;
        vector<vector<pair<ll, ll>>> graph(n+1);

        for (int i = 0; i<m; i++){
            ll a, b, d; cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, -d}); 
        }
        vl pos(n+1, 0);
        vi vis(n+1, 0);
        for (int i = 1; i<=n; i++){
            if (!vis[i]) dfs(graph, pos, i, vis);
        }
        if (ans) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    
    return 0;
}