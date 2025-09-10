// O(n*log(n))
// 1) init(adj,n);
struct CentroidDecomposition{
	vector<vi> adj;
	vi dad,sz,proc;

	int operator[](int i){return dad[i];}
	void init(vector<vi>& adj2, int n){
		proc.assign(n,false);
		dad.resize(n);
		sz.resize(n);
		adj=adj2;
		build();
	}

	void build(int v=0, int p=-1){
		int n=dfsSz(v, p); 
		int centroid=dfsCentroid(v, p, n);
		dad[centroid]=p;
		// anadir dfs para el conteo de caminos
		proc[centroid]=true;
		for(int u:adj[centroid]){
			if(u==p || proc[u])continue;
			build(u,centroid);
		}
	}

	int dfsSz(int v,int p){
		sz[v]=1;
		for(int u:adj[v]){
			if(u==p || proc[u])continue;
			sz[v]+=dfsSz(u, v);
		}
		return sz[v];
	}

	int dfsCentroid(int v, int p, int n){
		for(int u:adj[v]){
			if(u==p || proc[u])continue;
			if(sz[u]>n/2)return dfsCentroid(u,v,n);
		}
		return v;
	}
};

// para el arbol de centroides
// for(int b=a;b!=-1;b=cd[b])