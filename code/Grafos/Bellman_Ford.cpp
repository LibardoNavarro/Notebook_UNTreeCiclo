void bellman_ford(){
    vi dist(V, INF); dist[s] = 0;
    for (int i = 0; i < V-1; ++i)
        for (int u = 0; u < V; ++u)
            if (dist[u] != INF)
            for (auto &[v, w] : adj[u])
                dist[v] = min(dist[v], dist[u]+w);
}