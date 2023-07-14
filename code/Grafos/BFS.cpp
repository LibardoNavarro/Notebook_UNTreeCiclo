//BFS, complejidad O(V + E)
queue<int> q; q.push(adj[1][0]);    //Origen
vi d(n+1, INT_MAX); d[adj[1][0]] = 0;   //La distancia del vertice a el mismo es cero
while(!q.empty()){
    int nodo = q.front(); q.pop();
    for (int i = 0; i<(int)adj[nodo].size(); i++){
        if (d[adj[nodo][i]] == INT_MAX){   //Si el vecino no visitado y alcanzable
            d[adj[nodo][i]] = d[nodo] + 1;    //Hacer d[adj[u][i]] != INT_MAX para etiquetarlo
            q.push(adj[nodo][i]);          //Anadiendo a la cola para siguiente iteracion
            }
        }
    }
}