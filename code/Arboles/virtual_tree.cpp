const int maxn = 2e5+5;
vector<int> adjVT[maxn], adj[maxn];
bool important[maxn];
int st[maxn]; // tiempo inicial de v en euler tour
int ft[maxn]; // tiempo final de v en euler tour
int pos=0;

void dfs(int v, int p=-1){
	st[v]=pos++;
	for(int u:adj[v]){
		if(u==p)continue;
		dfs(u, v);
	}
	ft[v]=pos++;
}

// anadir LCA
int lca(int a, int b);
bool upper(int v, int u){return st[v]<=st[u] && ft[v]>=ft[u];}
bool cmp(int v, int u){return st[v]<st[u];}

// O(k*log(k))
// 1) actualizar important[]
// 2) returna root 
// 4) DP con virtual tree
// 3) limpiar important[]
int virtualTree(vector<int> nodes){
	sort(all(nodes), cmp);
	int m=sz(nodes);
	for(int i=0;i<m-1;++i){
		int v=lca(nodes[i], nodes[i+1]);
		nodes.push_back(v);
	}

	sort(all(nodes), cmp);
	nodes.erase(unique(all(nodes)), nodes.end());
	for(int u:nodes)adjVT[u].clear();

	vector<int> s;
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
