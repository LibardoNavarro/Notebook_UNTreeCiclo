#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nodes, edges;
    cin >> nodes >> edges;
    //Adjacency list
    vector<vector<int>> adj(nodes + 1);
    //Si es ponderado es un vector de vectores de pairs (indice vertice, peso arista)
    // vector<vector<pair<int, int>>> adj(nodes + 1);
    for (int i = 0; i<edges; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}