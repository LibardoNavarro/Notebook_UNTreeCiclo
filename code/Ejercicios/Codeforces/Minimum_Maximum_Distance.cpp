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

ii bfs(vector<vi> &adj, set<int> &marked, int u, int n){
    vi d(n+1, -1); d[u] = 0;
    queue<int> q; q.push(u);

    while (!q.empty()){
        u = q.front(); q.pop();
        for (int v : adj[u]){
            if (d[v] == -1){
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }

    int ans = 0;
    int maximo = -INF;

    for (int i = 1; i<=n; i++){
        if (maximo < d[i] && marked.count(i)){
            maximo = d[i];
            ans = i;
        }
    }

    return {ans, maximo};

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20) << fixed;

    int t; cin >> t;
    
    while (t--){
        int n, k; cin >> n >> k;
        set<int> marked;
        int x;
        for (int i = 0; i<k; i++) {cin >> x; marked.insert(x);}

        vector<vi> adj(n+1);
        for (int i = 0; i<n-1; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans1 = bfs(adj, marked, x, n).first;
        int ans2 = bfs(adj, marked, ans1, n).second;

        cout << ceil(ans2/2.0) << ln;
    }

    return 0;
}