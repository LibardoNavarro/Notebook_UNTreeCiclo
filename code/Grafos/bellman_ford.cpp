// O(V*E)
vi bellman_ford(vector<vii> &adj, int s, int n){
	vi dist(n, INF); dist[s] = 0;
	for (int i = 0; i<n-1; i++){
		bool modified = false;
		for (int u = 0; u<n; u++)
			if (dist[u] != INF)
				for (auto &[v, w] : adj[u]){
					if (dist[v] <= dist[u] + w) continue; 
					dist[v] = dist[u] + w;
					modified = true;
				}
		if (!modified) break;
	}

	bool negativeCicle = false;
	for (int u = 0; u<n; u++)
		if (dist[u] != INF)
			for (auto &[v, w] : adj[u]){
				if (dist[v] > dist[u] + w) negativeCicle = true;
			}

	return dist;
}