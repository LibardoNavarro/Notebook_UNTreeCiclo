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

void dijkstra(vector<vll> &adj, vl &d, int u){
    d[u] = 0;
    priority_queue<pll, vll, greater<pll>> pq;
    pq.push({0LL, u});
    while (!pq.empty()){
        pll nodo = pq.top(); pq.pop();
        int u = nodo.second; ll dist = nodo.first;
        if (dist > d[u]) continue;
        for (auto [v, w] : adj[u]){
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;
    vector<vll> adj(n+1);
    vector<vll> adj1(n+1);
    vector<pair<ll,ii>> edges;

    for (int i = 0; i<m; i++){
        int a, b; ll c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj1[b].push_back({a, c});
        edges.push_back({c, {a, b}});
    }

    vl d1(n+1, INFL), d2(n+1, INFL);

    dijkstra(adj, d1, 1); dijkstra(adj1, d2, n);
    ll ans = INFL;
    for (auto edge : edges){
        ll w = edge.first, a = edge.second.first, b = edge.second.second;
        ll temp = d1[a] + w/2 + d2[b];
        ans = min(temp, ans);
    }

    cout << ans << ln;

    return 0;
}