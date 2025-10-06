// O(n*log(n)) build
// O(log(n)) kth, lca, dist
struct LCA{
	vector<vi> up;
	vi dep;
	int n,maxlog;

	void build(vector<vi>& adj, int root){
		n=sz(adj);
		maxlog=ceil(log2(n))+3;
		up.assign(n, vi(maxlog, -1));
		dep.assign(n,0);
		dfs(adj,root);
		calc(n);
	}

	void dfs(vector<vi>& adj, int v=0, int p=-1){
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

	// kth ancestor, return -1 if it doesnt exits
	int kth(int u, int k){ 
		for(int l=maxlog-1;l>=0;--l){
			if(u!=-1 && k&(1<<l)){
				u=up[u][l];
			}
		}
		return u;
	}

	int lca(int a, int b){
		// if(kth(a, dep[a])!=kth(b, dep[b]))return -1; // forest
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
