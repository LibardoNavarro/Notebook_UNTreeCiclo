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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    for (int z = 1; z<=N; z++){
        int n, m, s, t; cin >> n >> m >> s >> t;
        vector<vii> adj(n);
        for (int i = 0; i<m; i++){
            int x, y, w; cin >> x >> y >> w;
            ii a = {y, w};
            ii b = {x, w};
            adj[x].push_back(a);
            adj[y].push_back(b);
        }
        vi caminos = dijkstra(adj, s, n);
        if (caminos[t] == INT_MAX) cout << "Case #" << z << ": " << "unreachable" << "\n";
        else cout << "Case #" << z << ": " << caminos[t] << "\n";
    }
}