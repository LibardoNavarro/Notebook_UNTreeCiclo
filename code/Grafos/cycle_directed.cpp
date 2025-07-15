vector<vi> adj;
vi parent,color;
int cy0, cy1;

bool dfs(int v){ 
	color[v]=1;
	for(int u:adj[v]){
		if(color[u]==0){
			parent[u]=v;
			if(dfs(u))return true;
		}else if(color[u]==1){
			cy1=v;
			cy0=u;
			return true;
		}
	}
	color[v]=2;
	return false;
}

// O(m)
void find_cycle(int n){
	color.assign(n, 0); 
	parent.assign(n, -1);
	cy0=-1;
	for(int v=0;v<n;++v){
		if(color[v]==0){
			if(dfs(v))break;
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
	reverse(cycle.begin(),cycle.end()); 
	print(cycle);
}
