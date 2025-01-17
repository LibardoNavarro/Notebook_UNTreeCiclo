const int maxn = 1e5+5;
vector<int> adj[maxn];
int len[maxn], pos=0;
int st[maxn], ft[maxn], ver[2*maxn];

void dfs0(int v=0, int p=-1){
	ver[pos]=v;
	st[v]=pos++;
	for(int u:adj[v]){
		if(u==p)continue;
		dfs0(u,v);
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

// O(nlogn)
void dfs1(int v=0, int p=-1, bool keep=true){
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
			dfs1(u,v,0); 
	}
	if(id!=-1)dfs1(id,v,1); 
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