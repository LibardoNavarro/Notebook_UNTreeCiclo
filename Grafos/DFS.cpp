#include <bits/stdc++.h>
using namespace std;

int vertices, aristas;

vector<int> dfs_num(vertices+1, -1); //Vector del estado de cada vertice (visitado o no visitado)

const int NO_VISITADO = -1;
const int VISITADO = 1;

vector<vector<int>> adj(vertices + 1); //Lista adjunta del grafo

// Complejidad O(V + E)
void dfs(int v){
    dfs_num[v] = VISITADO;
    //Se recorren los vecinos
    for (int i = 0; i < (int) adj[v].size(); i++){ 

        if (dfs_num[adj[v][i]] == NO_VISITADO){
            dfs(adj[v][i]);
        }

    }
}