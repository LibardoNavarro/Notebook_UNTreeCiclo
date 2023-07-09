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

    graphCheck(0);

    return 0;
}