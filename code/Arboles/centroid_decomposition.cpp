// O(n*log(n))
const int maxn = 1e5+1;
struct CentroidDecomposition{
	int dad[maxn],sz[maxn];
	set<int> adj[maxn];
	// si da TLE cambiar por processed

	int operator[](int i){return dad[i];}
	void addEdge(int x,int y){
		adj[x].insert(y);
		adj[y].insert(x);
	}

	void build(int v=0, int p=-1){
		int n=dfsSz(v, p); 
		int centroid=dfsCentroid(v, p, n);
		dad[centroid]=p;
		// anadir dfs para el conteo de caminos
		for(int u:adj[centroid]){
			adj[u].erase(centroid);
			build(u,centroid);
		}
		adj[centroid].clear();
	}

	int dfsSz(int v,int p){
		sz[v]=1;
		for(int u:adj[v]){
			if(u==p)continue;
			sz[v]+=dfsSz(u, v);
		}
		return sz[v];
	}

	int dfsCentroid(int v, int p, int n){
		for(int u:adj[v]){
			if(u==p)continue;
			if(sz[u]>n/2)return dfsCentroid(u,v,n);
		}
		return v;
	}
};

// para el arbol de centroides
// for(int b=a;b!=-1;b=cd[b])