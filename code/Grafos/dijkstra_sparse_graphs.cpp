// O(E*log(V))
vl dijkstra(vector<vector<pll>> &adj, int s, int n){
	vl dist(n, INFL); dist[s] = 0;
	set<pll> pq; 
	pq.insert(pll(0, s));
	while(!pq.empty()){
		pll front = *pq.begin(); pq.erase(pq.begin());
		ll d = front.first, u = front.second;
		for (auto &[v, w] : adj[u]){
			if (dist[u] + w < dist[v]){
				pq.erase(pll(dist[v], v));
				dist[v] = dist[u] + w;
				pq.insert(pll(dist[v], v));
			}
		}
	}
	return dist;
}