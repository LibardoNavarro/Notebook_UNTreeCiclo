// anadir RMQ - Min
typedef int T;
struct Table{
	void build(vector<T>& a);
	int get(int l, int r);
};

// O(n*log(n)) build
// O(1) lca
struct LCA{
	vector<int> time, path, tmp;
	Table rmq;
	int n,ti;

	void build(vector<vector<int>>& adj, int root){
		n=sz(adj);ti=0;
		time.resize(n);
		dfs(adj, root);
		rmq.build(tmp);
	}

	void dfs(vector<vector<int>>& adj, int u, int p=-1){
		time[u]=ti++;
		for(int v:adj[u]){
			if(v==p)continue;
			path.push_back(u);
			tmp.push_back(time[u]);
			dfs(adj, v, u);
		}
	}

	int lca(int a, int b){
		if(a==b)return a;
		a=time[a],b=time[b];
		if(a>b)swap(a,b);
		return path[rmq.get(a,b-1)];
	}
};