// O(|E|*|V|)
struct mbm {
	int l, r;
	vector<vector<int>> g;
	vector<int> match, seen;
	mbm(int l, int r) : l(l), r(r), g(l), match(r), seen(r){}
	void add_edge(int l, int r) { g[l].push_back(r); }
	bool dfs(int u) {
		for(auto v : g[u]) {
			if(seen[v]++) continue;
			if(match[v] == -1 || dfs(match[v])) {
				match[v] = u;
				return true;
			}
		}
		return false;
	}
	int max_matching() {
		int ans = 0;
		fill(match.begin(), match.end(), -1);
		for(int u = 0; u < l; ++u) {
			fill(seen.begin(), seen.end(), 0);
			ans += dfs(u);
		}
		return ans;
	}
	void matchs(){
		for (int i = 0; i<r; i++){
			if (match[i] == -1) continue;
			cout << match[i]+1  << ' ' << i+1 << ln;
		}
	}
};