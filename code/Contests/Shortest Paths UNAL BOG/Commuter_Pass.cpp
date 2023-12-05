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

map<ii, bool> marked;

ll dijkstra(vector<vll> &adj, int s, int V, int t, vi &parent){
    vl dist(V+1, INFL); dist[s] = 0;
    priority_queue<pll, vll, greater<pll> > pq; pq.push(pll(0LL, s));
    while(!pq.empty()){
        pll front = pq.top(); pq.pop();
        ll d = front.first, u = front.second;
        if (d > dist[u]) continue;

        for (int j = 0; j < (int)adj[u].size(); j++){
            pll v = adj[u][j];
            if (marked[{u, v.first}]) v.second = 0LL; 
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                parent[v.first] = u;
                pq.push(pll(dist[v.first], v.first));
            }
        }
    }
    return dist[t];
}

void path(vi &p, int s, int t, vi &ans){
    if (s == t) {ans.push_back(t); return;}
    path(p, s, p[t], ans);
    ans.push_back(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t;
    int u, v; cin >> u >> v;

    vector<vll> adj(n+1);
    for (int i = 0; i<m; i++){
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vi p(n+1, -1);
    dijkstra(adj, s, n, t, p);
    vi camino;
    path(p, s, t, camino);
    for (int i = 0; i<sz(camino)-1; i++) {
        marked[{camino[i], camino[i+1]}] = true;
        marked[{camino[i+1], camino[i]}] = true;
    }

    cout << dijkstra(adj, u, n, v, p) << ln;

    return 0;
}