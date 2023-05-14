#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

vi dijkstra(vector<vii> adj, int s, int V){
    vi dist(V+1, INT_MAX); dist[s] = 0;
    priority_queue<ii, vii, greater<ii> > pq; pq.push(ii(0, s));
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;

        for (int j = 0; j < (int)adj[u].size(); j++){
            ii v = adj[u][j];
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true){
        int n, m, q, s; cin >> n >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s ==0) break;
        vector<vii> adj(n);

        for (int i = 0; i<m; i++){
            int x, y, w; cin >> x >> y >> w;
            ii a = {y, w};
            adj[x].push_back(a);
        }

        vi distacias = dijkstra(adj, s, n);

        for (int i = 0; i<q; i++){
            int y; cin >> y;
            if (distacias[y] == INT_MAX) cout << "Impossible" << "\n";
            else cout << distacias[y] << "\n";
        }
        cout << "\n";
    }
}