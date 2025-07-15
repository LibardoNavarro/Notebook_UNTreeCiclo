const int maxn = 1e5+5;
// construir el grafo inverso
// remember adj[a]->b, adj_rev[b]->a
vi adj_rev[maxn],adj[maxn]; 
bool used[maxn];
int idx[maxn]; // componente de cada nodo
vi order,comp;

// O(n+m)
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

// returna el numero de componentes
int init(int n){ 
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
	return j;
}