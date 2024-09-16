const int maxn = 1e5+5;
vector<int> adj[maxn];
int nodes[maxn],ver[2*maxn],dep[maxn],st[maxn],ft[maxn],n,pos=0;

void prec(int v=0, int p=-1){
	nodes[v]=1;
	ver[pos]=v;
	st[v]=pos++;
	for(int u:adj[v]){
		if(u==p)continue;
		dep[u]=dep[v]+1;
		prec(u,v);
		nodes[v]+=nodes[u];
	}
	ver[pos]=v;
	ft[v]=pos++;
}

bool vis[maxn];
void ask(int v, bool add){
	if(vis[v] && !add){
		vis[v]=false;
		// delete node
	}else if(!vis[v] && add){
		vis[v]=true;
		// add node
	}
}

void dfs(int v=0, int p=-1, bool keep=true){
	int mx=0,id=-1;
	for(int u:adj[v]){
		if(u==p)continue;
		if(nodes[u]>mx){
			mx=nodes[u];
			id=u;
		}
	}
	for(int u:adj[v]){
		if(u==p || u==id)continue;
		dfs(u,v,0); 
	}
	if(id!=-1)dfs(id,v,1); 
	for(int u:adj[v]){
		if(u==p || u==id)continue;
		for(int p=st[u];p<ft[u];++p)ask(ver[p], 1);
	}
	ask(v, 1);
	// answer queries
	if(keep==0){
		for(int p=st[v];p<ft[v];++p)ask(ver[p], 0);
	}
}
