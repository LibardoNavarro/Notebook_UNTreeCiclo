#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

vi dijkstra(vector<vii> &adj, int s, int V, vi &p){
    vi dist(V+1, LONG_LONG_MAX); dist[s] = 0;
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

void printPath(int u, int s, vi &p){
    if (u == s) {cout << s << " "; return;}
    printPath(p[u], s, p);
    cout << u << " ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vi p(n+1);
    vector<vii> adj(n+1);
    for (int i = 0; i<m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    dijkstra(adj, 1, n, p);
    if (!p[n]) cout << -1 << "\n";
    else printPath(n, 1, p);
}