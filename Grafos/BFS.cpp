#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
vector<vi> adj;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //BFS, complejidad O(V + E)
    queue<int> q; q.push(adj[1][0]);    //Origen
    vi d(n+1, INT_MAX); d[adj[1][0]] = 0;   //La distancia del vertice a el mismo es cero
    while(!q.empty()){
        int nodo = q.front(); q.pop();
        for (int i = 0; i<(int)adj[nodo].size(); i++){
            if (d[adj[nodo][i]] == INT_MAX){   //Si el vecino no visitado y alcanzable
                d[adj[nodo][i]] = d[nodo] - 1;    //Hacer d[adj[u][i]] != INT_MAX para etiquetarlo
                q.push(adj[nodo][i]);          //Añadiendo a la cola para siguiente iteracion
            }
        }
    }
}