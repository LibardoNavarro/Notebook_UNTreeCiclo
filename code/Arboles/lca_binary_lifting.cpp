// O(n*log(n)) build
// O(log(n)) kth, lca, dist
struct LCA{
	vector<vector<int>> up;
	vector<int> dep;
	int n,maxlog;

	void build(vector<vector<int>>& adj, int root){
		n=sz(adj);
		maxlog=ceil(log2(n))+3;
		up.assign(n, vector<int>(maxlog, -1));
		dep.assign(n,0);
		dfs(adj,root);
		calc(n);
	}

	void dfs(vector<vector<int>>& adj, int v=0, int p=-1){
		up[v][0]=p;
		for(int u:adj[v]){
			if(u==p)continue;
			dep[u]=dep[v]+1;
			dfs(adj, u, v);
		}
	}

	void calc(int n){
		for(int l=1;l<maxlog;++l){
			for(int i=0;i<n;++i){
				if(up[i][l-1]!=-1){
					up[i][l]=up[up[i][l-1]][l-1];
				}
			}
		} 
	}

	// kth ancestor, retorna -1 si no existe
	int kth(int u, int k){ 
		for(int l=maxlog-1;l>=0;--l){
			if(u!=-1 && k&(1<<l)){
				u=up[u][l];
			}
		}
		return u;
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

	int dist(int a, int b){
		return dep[a]+dep[b]-2*dep[lca(a,b)];
	}
};
