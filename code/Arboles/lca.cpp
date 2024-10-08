const int maxn = 2e5+5, maxlog = 20+5; 
int up[maxn][maxlog], dep[maxn]; // memset -1 (up)
vi adj[maxn];

void dfs(int v=0, int p=-1){
	up[v][0]=p;
	for(int u:adj[v]){
		if(u!=p){
			dep[u]=dep[v]+1;
			dfs(u, v);
		}
	}
}

void build(int n){
	for(int l=1;l<maxlog;++l){
		for(int i=0;i<n;++i){
			if(up[i][l-1]!=-1){
				up[i][l]=up[up[i][l-1]][l-1];
			}
		}
	} 
}

int kth(int node, int k){
	for(int l=maxlog-1;l>=0;--l){
		if(node!=-1 && k&(1<<l)){
			node=up[node][l];
		}
	}
	return node;
}

int lca(int a, int b){
	a=kth(a, dep[a]-min(dep[a], dep[b]));
	b=kth(b, dep[b]-min(dep[a], dep[b]));
	if(a==b)return a;
	for(int l=maxlog-1;l>=0;--l){
		if(up[a][l]!=up[b][l]){
			a=up[a][l];
			b=up[b][l];
		}
	}
	return up[a][0];
}
