const int maxn = 1e5+5;
int st[maxn], ft[maxn], ver[2*maxn];
int len[maxn], n, q, pos=0;
vi adj[maxn];

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

// O(nlogn)
void dfs(int v=0, int p=-1, bool keep=true){
	int mx=0,id=-1;
	for(int u:adj[v]){
		if(u==p)continue;
		if(len[u]>mx){
			mx=len[u];
			id=u;
		}
	}
	for(int u:adj[v]){
		if(u!=p && u!=id)
			dfs(u,v,0); 
	}
	if(id!=-1)dfs(id,v,1); 
	for(int u:adj[v]){
		if(u==p || u==id)continue;
		for(int p=st[u];p<ft[u];++p)
			ask(ver[p], 1);
	}
	ask(v, 1);
	// answer queries
	if(keep)return;
	for(int p=st[v];p<ft[v];++p)
		ask(ver[p], 0);
}