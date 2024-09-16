const int maxlog = 20+5; 
const int maxn = 2e5+5;
bool important[maxn];
vector<int> adjVT[maxn],adj[maxn];
int st[maxn], ft[maxn],up[maxn][maxlog],dep[maxn],n,q,pos=0; 

void dfs(int v, int p=-1){
	up[v][0]=p;
	st[v]=++pos;
	for(int u:adj[v]){
		if(u==p)continue;
		dep[u]=dep[v]+1;
		dfs(u, v);
	}
	ft[v]=pos;
}

int lca(int a, int b);
bool upper(int v, int u){return st[v]<=st[u] && ft[v]>=ft[u];}
bool cmp(int v, int u){return st[v]<st[u];}
int virtualTree(vector<int> nodes){	// O(klogk)
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
			adjVT[s[sz(s)-2]].push_back(s.back()); // add edge
			s.pop_back();
		}
		s.push_back(v);
	}
	while(sz(s)>=2){
		adjVT[s[sz(s)-2]].push_back(s.back()); // add edge
		s.pop_back();
	}
	return s[0];
}

// int k;cin>>k;
// vector<int> nodes(k);
// for(int& x:nodes)important[x]=true;
// int root=virtualTree(nodes);
// dp(root);
// output answer
// reset
