vector<vi> adj;
vector<bool> visited; 
int cy0,cy1;
vi parent;

bool dfs(int v, int par){ 
	visited[v]=true;
	for(int u:adj[v]){
		if(u==par)continue;
		if(visited[u]){
			cy1=v;
			cy0=u;
			return true;
		}
		parent[u]=v;
		if(dfs(u,parent[u]))return true;
	}
	return false;
}

// O(m)
void find_cycle(int n){
	visited.assign(n, false); 
	parent.assign(n, -1);
	cy0=-1;
	for(int v=0;v<n;++v){
		if(!visited[v]){
		if(dfs(v, parent[v]))break;
		}
	}
	if(cy0==-1){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	vi cycle;
	cycle.push_back(cy0);
	for(int v=cy1;v!=cy0;v=parent[v])cycle.push_back(v);
	cycle.push_back(cy0);
	print(cycle);
}
