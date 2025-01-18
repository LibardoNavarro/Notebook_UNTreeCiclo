// O ((V+E)*log V)
vl dijkstra(vector<vector<pll>> &adj, int s, int n){
	vl dist(n, INFL); dist[s] = 0;
	priority_queue<pll, vector<pll>, greater<pll> > pq; pq.push(pll(0, s));
	while(!pq.empty()){
		pll front = pq.top(); pq.pop();
		ll d = front.first, u = front.second;
		if (d > dist[u]) continue;

		for (auto &[v, w] : adj[u]){
			if (dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push(pll(dist[v], v));
			}
		}
	}
	return dist;
}