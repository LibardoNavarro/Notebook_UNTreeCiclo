const int maxn = 1e5+5;
vector<int> adj[maxn],path;
int out[maxn],in[maxn]; // remember

void dfs(int v){
	while(!adj[v].empty()){
		int u=adj[v].back();
		adj[v].pop_back();
		dfs(u);
	}
	path.push_back(v);
}

// n -> nodes, m -> edges, s -> start, e -> end
void eulerian_path(int n, int m, int s, int e){ 
	for(int i=0;i<n;++i){
		if(i==s || i==e)continue;
		if(in[i]!=out[i]){
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}
	if(out[s]-in[s]!=1 || in[e]-out[e]!=1){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	dfs(s);
	reverse(path.begin(), path.end());
	if(sz(path)!=m+1 || path.back()!=e)cout<<"IMPOSSIBLE\n";
	else print(path);
}
