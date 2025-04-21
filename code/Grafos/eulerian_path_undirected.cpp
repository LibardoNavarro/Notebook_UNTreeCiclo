const int maxn = 1e5+5;
const int maxm = 2e5+5;
vector<ii> adj[maxn]; // adj[a].push_back({b, i});
vector<int> path;
int grade[maxn]; // remember
bool vis[maxm];

void dfs(int v){
	while(!adj[v].empty()){
		ii x=adj[v].back();
		adj[v].pop_back();
		if(vis[x.second])continue;
		vis[x.second]=true;
		dfs(x.first);
	}
	path.push_back(v+1);
}

// check if end is equal to start
void eulerian_path(int n, int m, int s){
	for(int i=0;i<n;++i){
		if(grade[i]%2!=0){
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}
	dfs(s);
	if(sz(path)!=m+1)cout<<"IMPOSSIBLE\n";
	else print(path);
}
