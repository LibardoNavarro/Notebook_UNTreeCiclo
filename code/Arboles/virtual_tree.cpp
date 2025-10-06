// O(k*log(k))
// 1) build(n,root,adj);
// 2) query(nodes);

LCA g; // Add LCA
int lca(int a, int b){return g.lca(a,b);};
struct VirtualTree{
	vector<vi> adj,adjVT;
	vector<int> st,ft;
	vector<bool> important;
	int pos=0;

	void build(vector<vi>& adj2, int n, int root){
		important.assign(n,false);
		adjVT.assign(n,vi());
		st.resize(n);
		ft.resize(n);
		adj=adj2;pos=0;
		dfs(root);
	}

	void dfs(int v, int p=-1){
		st[v]=pos++;
		for(int u:adj[v]){
			if(u==p)continue;
			dfs(u, v);
		}
		ft[v]=pos++;
	}

	bool upper(int v, int u){return st[v]<=st[u] && ft[v]>=ft[u];}

	int getRootVirtualTree(vi nodes){
		sort(all(nodes), [&](int v, int u){ return st[v] < st[u]; });
		int m=sz(nodes);
		for(int i=0;i<m-1;++i){
			int v=lca(nodes[i], nodes[i+1]);
			nodes.push_back(v);
		}
		
		sort(all(nodes), [&](int v, int u){ return st[v] < st[u]; });
		nodes.erase(unique(all(nodes)), nodes.end());
		for(int u:nodes)adjVT[u].clear();

		vi s;
		s.push_back(nodes[0]);
		m=sz(nodes);
		for(int i=1;i<m;++i){
			int v=nodes[i];
			while(sz(s)>=2 && !upper(s.back(), v)){
				adjVT[s[sz(s)-2]].push_back(s.back()); 
				s.pop_back();
			}
			s.push_back(v);
		}
		while(sz(s)>=2){
			adjVT[s[sz(s)-2]].push_back(s.back()); 
			s.pop_back();
		}
		return s[0];
	}

	void dfs2(int u, int p=-1){
		if(important[u]){
			// pass
		}else{
			// pass
		}
		for(int v:adjVT[u]){
			if(v==p)continue;
			dfs2(v,u);
		}
	}

	void query(vi& nodes){
		for(int u:nodes)important[u]=true;
		int root=getRootVirtualTree(nodes);
		dfs2(root);
		// cout ans
		for(int u:nodes)important[u]=false;
	}
};