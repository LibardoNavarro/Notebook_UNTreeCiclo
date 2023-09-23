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

void dijkstra(vector<vii> &adj, vl &d, int u){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0LL, u});
    while (!pq.empty()){
        auto nodo = pq.top(); pq.pop();
        ll u = nodo.second, dis = nodo.first;
        if (dis >= d[u]) continue;
        d[u] = dis;
        for (ii vecino : adj[u]){
            ll v = vecino.first, w = vecino.second;
            if (d[v] > d[u] + w) pq.push({d[u] + w, v});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;
    vector<vii> adj(n+1);
    for (int i = 0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vl d(n+1, INFL);
    dijkstra(adj, d, 1);
    for (int i = 1; i<=n; i++) cout << d[i] << " ";
    
    return 0;
}