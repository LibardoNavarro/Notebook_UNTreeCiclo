#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vi> adj;
 
 
bool bfs(int v, vi &color){
    queue<int> q; q.push(v); color[v] = 0;
    bool isBipartito = true;
    while(!q.empty() && isBipartito){
        int nodo = q.front(); q.pop();
 
        for (int j = 0; j< (int) adj[nodo].size(); j++){
            if (color[adj[nodo][j]] == INT_MAX){
                color[adj[nodo][j]] = 1 - color[nodo];
                q.push(adj[nodo][j]);
            }
 
            else if (color[adj[nodo][j]] == color[nodo]){
                isBipartito = false; break;
            }
        }
    }
    return isBipartito;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    vi color(n+1, INT_MAX);
 
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    bool ans = true;
 
    for (int i = 1; i<=n; i++){
        if (color[i] == INT_MAX){
            if (!bfs(i, color)){
                ans = false; break;
            }
        }
    }
 
    if (ans){
        for (int i = 1; i<=n; i++) cout << color[i]+1 << " ";
    }
    else cout << "IMPOSSIBLE";
 
}