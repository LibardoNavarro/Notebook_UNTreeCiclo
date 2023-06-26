#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nodes, edges;
    cin >> nodes >> edges;
    //Adjacency matrix
    vector<vector<int>> adj(nodes+1, vector<int>(nodes+1, 0));

    for (int i = 0; i<edges; i++){
        //edges
        int u, v;
        cin >> u >> v;
        // Se asigna uno o el peso si es un grafo ponderado
        adj[u][v] = 1; 
        adj[v][u] = 1;
    }

    return 0;
}