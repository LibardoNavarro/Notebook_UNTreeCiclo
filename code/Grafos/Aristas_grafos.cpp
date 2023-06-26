#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

/*
EXPLORED = 2 (visitado pero no completado)
VISITED (visitado y completado)
TIPOS DE ARISTAS
1. Arista de arbol: la arista recorrida por DFS, es decir, una arista de un vertice con estado EXPLORED
a un vertice con estado UNVISITED
2. Arista inversa: una arista que es parte de un ciclo, es decir, una arista de un vertice con estado EXPLORED
a un vertice tambien EXPLORED. Hay que tener en cuenta que normalmente no consideramos que las aristas bidireccionales
tengan un "ciclo" (debemos recordar dfs_parent para distinguir esto)
3. Aristas adelante/cruzadas: de un vertice con estado EXPLORED a otro con estado VISITED.
*/
vector<vi> adj;
vi dfs_num;
vi dfs_parent;
int EXPLORED = 2;
int VISITED = 1;
int UNVISITED = -1;
void graphCheck(int u){//DFS para comprobar las propiedades de la arista
    dfs_num[u] = EXPLORED;
    for (int j = 0; j< (int)adj[u].size(); j++){
        int v = adj[u][j];
        if (dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            graphCheck(v);
        }
        else if(dfs_num[v] == EXPLORED){
            if (v == dfs_parent[u]) 
            cout << "Dos caminos " << "(" << u << ", " << v << ") - (" << v << ", " << u << ")\n";
            else
            cout << "Back Edge (" << u << ", " << v << ") (Ciclo)\n";
        }
        else if(dfs_num[v] == VISITED)
        cout << "Arista adelante/cruzada (" << u << ", " << v << ")\n";
    }
    dfs_num[u] = VISITED;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nodes, edges;
    cin >> nodes >> edges;
    //Adjacency list
    adj.resize(nodes + 1);
    dfs_num.assign(nodes + 1, UNVISITED);
    dfs_parent.assign(nodes + 1, 0);
    for (int i = 0; i<edges; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    graphCheck(0);

    return 0;
}