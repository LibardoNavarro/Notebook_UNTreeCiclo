#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
vector<vi> adj;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin >> n;
    adj.resize(n+1);
    for (int i = 0; i<n-1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q; q.push(adj[1][0]);
    vi color(n+1, INT_MAX); color[adj[1][0]] = 0;
    bool esBipartito = true;
    while(!q.empty() && esBipartito){
        int u = q.front(); q.pop();
        for (int i = 0; i<(int)adj[u].size(); i++){
            if (color[adj[u][i]] == INT_MAX){       //En vez de guardar la distancia
                color[adj[u][i]] = 1 - color[u];    //solo guardamos dos colores {0, 1}
                q.push(adj[u][i]);
            }
            else if(color[adj[u][i]] == color[u]){  //Si vecinos son de un mismo color
                esBipartito = false; break;         //no es bipartito
            }
        }
    }
}