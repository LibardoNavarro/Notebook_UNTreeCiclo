#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

int n, m;
vector<vi> adj;
vi grado;
vi orden;

void bfs(){
    queue<int> q;

    for (int i = 1; i<=n; i++){
        if (!grado[i]) q.push(i);
    }
    int nodo;

    while(!q.empty()){
        nodo = q.front(); q.pop();
        orden.push_back(nodo);
        for (int v : adj[nodo]){
            grado[v]--;
            if (grado[v] == 0) q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    grado.resize(n+1);

    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        grado[y]++;
    }
    
    bfs();

    if (orden.size() == n){
        for (int i : orden) cout << i;
    }
    else{
        cout << "No DAG"; //No es un grafo aciclico dirigido (tiene un ciclo)
    }
}