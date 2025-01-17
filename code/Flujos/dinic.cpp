// O(|E|*|V|^2)
struct edge { ll v, cap, inv, flow, ori; };
struct network {
	ll n, s, t;
	vector<ll> lvl;
	vector<vector<edge>> g;
	network(ll n) : n(n), lvl(n), g(n) {}
	void add_edge(int u, int v, ll c) {
		g[u].push_back({v, c, sz(g[v]), 0, 1});
		g[v].push_back({u, 0, sz(g[u])-1, c, 0});
	}
	bool bfs() {
		fill(lvl.begin(), lvl.end(), -1);
		queue<ll> q;
		lvl[s] = 0;
		for(q.push(s); q.size(); q.pop()) {
			ll u = q.front();
			for(auto &e : g[u]) {
				if(e.cap > 0 && lvl[e.v] == -1) {
					lvl[e.v] = lvl[u]+1;
					q.push(e.v);
				}
			}
		}
		return lvl[t] != -1;
	}
	ll dfs(ll u, ll nf) {
		if(u == t) return nf;
		ll res = 0;
		for(auto &e : g[u]) {
			if(e.cap > 0 && lvl[e.v] == lvl[u]+1) {
				ll tf = dfs(e.v, min(nf, e.cap));
				res += tf; nf -= tf; e.cap -= tf;
				g[e.v][e.inv].cap += tf;
				g[e.v][e.inv].flow -= tf;
				e.flow += tf;
				if(nf == 0) return res;
			}
		}
		if(!res) lvl[u] = -1;
		return res;
	}
	ll max_flow(ll so, ll si, ll res = 0) {
		s = so; t = si;
		while(bfs()) res += dfs(s, LONG_LONG_MAX);
		return res;
	}
	void min_cut(){
		queue<ll> q;
		vector<bool> vis(n, 0);
		vis[s] = 1;
		for(q.push(s); q.size(); q.pop()) {
			ll u = q.front();
			for(auto &e : g[u]) {
				if(e.cap > 0 && !vis[e.v]) {
					q.push(e.v);
					vis[e.v] = 1;
				}
			}
		}
		vii ans;
		for (int i = 0; i<n; i++){
			for (auto &e : g[i]){
				if (vis[i] && !vis[e.v] && e.ori){
					ans.push_back({i+1, e.v+1});
				}
			}
		}
		for (auto [x, y] : ans) cout << x << ' ' << y << ln;
	}
	bool dfs2(vi &path, vector<bool> &vis, int u){
		vis[u] = 1;
		for (auto &e : g[u]){
			if (e.flow > 0 && e.ori && !vis[e.v]){
				if (e.v == t || dfs2(path, vis, e.v)){
					path.push_back(e.v);
					e.flow = 0;
					return 1;
				}
			}
		}
		return 0;
	}
	void disjoint_paths(){
		vi path;
		vector<bool> vis(n, 0);
		while (dfs2(path, vis, s)){
			path.push_back(s);
			reverse(all(path));
			cout << sz(path) << ln;
			for (int v : path) cout << v+1 << ' ';
			cout << ln;
			path.clear(); vis.assign(n, 0);
		}
	}
};