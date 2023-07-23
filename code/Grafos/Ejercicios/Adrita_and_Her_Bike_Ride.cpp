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

vl dijkstra(vector<vii> &adj, int s, int V, vi &p){
    vl dist(V+1, INFL); dist[s] = 0;
    priority_queue<ii, vii, greater<ii> > pq; pq.push(ii(0, s));
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;

        for (int j = 0; j < (int)adj[u].size(); j++){
            ii v = adj[u][j];
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                p[v.first] = u;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k; cin >> k;

    while (k--){
        int n, r, s, d; cin >> n >> r >> s >> d;
        vector<vii> adj(n+1);

        for (int i = 0; i<r; i++){
            ll u, v, t; cin >> u >> v >> t;
            adj[u].push_back({v, 12+t});
            adj[v].push_back({u, 12+t});
        }

        vi p(n+1);
        cout << dijkstra(adj, s, n, p)[d] << "\n";
    }

    return 0;
}