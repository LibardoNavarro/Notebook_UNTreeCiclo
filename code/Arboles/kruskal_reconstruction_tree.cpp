// Kruskal Reconstruction Tree (KRT)
// the main idea is to build a tree to efficiently answer queries
// about the minimum or maximum edge weight between two nodes.
// each edge will be represented as a node in the tree.
// query(a,b) = lca(a,b) 

// Add LCA

const int maxn = 1e5+5;
const int maxm = 2e5+5;
vector<vector<int>> adj;

// sometimes it is useful
int ver[2*(maxn+maxm)]; // node at position i in euler tour
int st[maxn+maxm]; // start time of v
int ft[maxn+maxm]; // finish time of v

struct DSU{
	vector<int> p,size;
	vector<bool> roots; // if the graph is a forest
	DSU(int n){
		p.assign(n,0);
		size.assign(n,1);
		roots.assign(n,true);
		for(int i=0;i<n;++i)p[i]=i;
	}
	int get(int a){return (a==p[a]?a:p[a]=get(p[a]));} 
	// unite node a and node b with the edge m => node m
	void unite(int a, int b, int m){
		a=get(a);b=get(b);
		if(a==b)return;
		size[m]=size[a]+size[b];
		p[a]=p[b]=m;
		roots[a]=false;
		roots[b]=false;
		adj[m].push_back(a);
		adj[m].push_back(b);
	}
};
