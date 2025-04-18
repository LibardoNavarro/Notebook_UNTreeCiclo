const int maxn = 1e5+5;
vi adj_rev[maxn],adj[maxn]; 
// construir el grafo inverso
// adj[a]->b, adj_rev[b]->a
bool used[maxn];
int idx[maxn]; // componente de cada nodo
vi order,comp;

void dfs1(int v){
	used[v]=true;
	for(int u:adj[v])
	if(!used[u])dfs1(u);
	order.push_back(v);
}

void dfs2(int v){
	used[v]=true;
	comp.push_back(v);
	for(int u:adj_rev[v])
	if(!used[u])dfs2(u);
}

// O(n+m)
void init(int n){
	for(int i=0;i<n;++i)if(!used[i])dfs1(i);
	for(int i=0;i<n;++i)used[i]=false;
	reverse(order.begin(), order.end());
	int j=0;
	for(int v:order){
		if(!used[v]){
			dfs2(v);
			for(int u:comp)idx[u]=j;
			comp.clear();
			j++;
		}
	}
}