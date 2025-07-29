// O(n) build
// bi_connected save the edges

const int maxn = 1e5+5;
int lowLink[maxn] , dfn[maxn];
vector<vector<ii>> bi_connected;
stack<ii> comps;	
int ndfn;

void tarjan(vector<vi>& adj, int u=0, int par=-1){
	dfn[u] = lowLink[u] = ndfn++;
	for(auto &v : adj[u]){
		if (v != par && dfn[v] < dfn[u])
			comps.push({u, v});
		if(dfn[v] == -1){
			tarjan(adj, v, u);
			lowLink[u] = min(lowLink[u] , lowLink[v]);
			if (lowLink[v] >= dfn[u]){
				bi_connected.emplace_back(vector<ii>());
				ii edge;
				do{
					edge = comps.top();
					comps.pop();
					bi_connected.back().emplace_back(edge);

				}while(edge.first != u || edge.second != v);
				reverse(all(bi_connected.back()));
			}
		}else if(v != par){
			lowLink[u] = min(lowLink[u] , dfn[v]);
		}
	}
}

void init(vector<vi>& adj){
	for(int i=0;i<sz(adj);++i)
		dfn[i]=-1;
	bi_connected.clear();
	comps=stack<ii>();
	ndfn=0;
	tarjan(adj);
}
