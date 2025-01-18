// O(V * E^2)
ll bfs(vector<vi> &adj, vector<vl> &capacity, int s, int t, vi& parent) {
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pll> q;
	q.push({s, INFL});

	while (!q.empty()) {
		int cur = q.front().first;
		ll flow = q.front().second;
		q.pop();

		for (int next : adj[cur]) {
			if (parent[next] == -1LL && capacity[cur][next]) {
				parent[next] = cur;
				ll new_flow = min(flow, capacity[cur][next]);
				if (next == t)
					return new_flow;
				q.push({next, new_flow});
			}
		}
	}

	return 0;
}

ll maxflow(vector<vi> &adj, vector<vl> &capacity, int s, int t, int n) {
	ll flow = 0;
	vi parent(n);
	ll new_flow;

	while ((new_flow = bfs(adj, capacity, s, t, parent))) {
		flow += new_flow;
		int cur = t;
		while (cur != s) {
			int prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}

	return flow;
}