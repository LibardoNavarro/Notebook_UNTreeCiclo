// O(n+m) build graph in g[] and callt()
const int maxn = 2e5 + 5;
vi low, num, comp, g[maxn];
int scc, timer;
stack<int> st;
void tjn(int u) {
	low[u] = num[u] = timer++; st.push(u); int v;
	for(int v: g[u]) {
		if(num[v]==-1) tjn(v);
		if(comp[v]==-1) low[u] = min(low[u], low[v]);
	}
	if(low[u]==num[u]) {
		do{ v = st.top(); st.pop(); comp[v]=scc;
		}while(u != v);
		++scc;
	}
}
void callt(int n) {
	timer = scc= 0;
	num = low = comp = vector<int>(n,-1);
	for(int i = 0; i<n; i++) if(num[i]==-1) tjn(i);
}