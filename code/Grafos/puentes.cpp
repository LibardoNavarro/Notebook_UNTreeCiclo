// O(n+m)
vector<bool> visited;
vi tin, low;
int timer;

void IS_BRIDGE(int u, int v, vii &puentes){
	puentes.push_back({min(u, v), max(u, v)});
}

void dfs(vector<vi> &adj, vii &puentes, int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	for (int to : adj[v]) {
		if (to == p) continue;
		if (visited[to]) {
			low[v] = min(low[v], tin[to]);
		} else {
			dfs(adj, puentes, to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] > tin[v])
				IS_BRIDGE(v, to, puentes);
			
		}
	}
}

void find_bridges(vector<vi> &adj, vii &puentes, int n) {
	timer = 0;
	visited.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!visited[i])
			dfs(adj, puentes, i);
	}
}