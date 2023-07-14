//Orden de un grafo estilo malla curricular de prerrequisitos
vector<vi> adj;
vi dfs_num;
vi ts;

void dfs(int v){
    dfs_num[v] = 1;
    for (int i = 0; i < (int) adj[v].size(); i++){ 

        if (dfs_num[adj[v][i]] != 1){
            dfs(adj[v][i]);
        }

    }
    ts.push_back(v);
}
//Imprimir el vector ts al reves: reverse(ts.begin(), ts.end());