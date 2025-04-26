// add LCA
struct LCA{
	void build();
	int lca(int a, int b);
};

vector<vector<int>> adj;
const int maxn=1e5+5;
int ver[2*maxn]; // node at position i in euler tour
int st[maxn]; // start time of v
int ft[maxn]; // finish time of v
int pos=0;
LCA tree;

// O((n+q)*sq), sq=n^(1/2)
// 1. build euler tour and lca
// 2. add queries[] 
// if(st[a]>st[b])swap(a,b);
// queries.push_back({st[a]+1,st[b],i});
// 3. solve(n);
// 4. print ans[]
int sq;

void dfs(int u=0, int p=-1){
	ver[pos]=u;
	st[u]=pos++;
	for(int v:adj[u]){
		if(v==p)continue;
		dfs(v,u);
	}
	ver[pos]=u;
	ft[u]=pos++;
}

struct query {int l,r,idx;};
bool cmp(query& a, query& b){
	int x=a.l/sq;
	if(a.l/sq!=b.l/sq)return a.l/sq<b.l/sq;
	return (x&1?a.r<b.r:a.r>b.r);
}

vector<query> queries;
vector<ll> ans;
bool vis[maxn];

ll act();
void add(int u);
void remove(int u);
void ask(int u){
	if(!vis[u])add(u);
	else remove(u);
	vis[u]=!vis[u];
}

void solve(int n){
	sq=ceil(sqrt(n));
	sort(all(queries), cmp);
    ans.resize(sz(queries));
	int l=0,r=-1;
    for(auto [li,ri,i]:queries){
		while(r<ri)ask(ver[++r]);
		while(l>li)ask(ver[--l]);
		while(r>ri)ask(ver[r--]);
		while(l<li)ask(ver[l++]);
		int a=ver[l-1],b=ver[r];
		int c=tree.lca(a,b);
		ask(c);
		ans[i]=act();
		ask(c);
	}
}
