const int maxn=1e5+5;
int st[maxn],ft[maxn],ver[2*maxn];
vector<int> adj[maxn];

// O((n+q)*s), s=n^(1/2)
int pos=0,s,n;
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

int lca(int a, int b);

struct query{int l,r,idx;};
bool cmp(query& a, query& b){
	int x=a.l/s;
	if(a.l/s!=b.l/s)return a.l/s<b.l/s;
	return (x&1?a.r<b.r:a.r>b.r);
}

vector<query> queries;
vector<ll> ans;
bool vis[maxn];

ll act();
void add(int u); // add value of node u
void remove(int u); // remove value of node u
void ask(int u){
	if(!vis[u])add(u);
	else remove(u);
	vis[u]=!vis[u];
}

void solve(){
	s=ceil(sqrt(n));
	sort(all(queries), cmp);
	ans.resize(sz(queries));
	int l=0,r=-1;
	for(auto [li,ri,i]:queries){
		while(r<ri)ask(ver[++r]);
		while(l>li)ask(ver[--l]);
		while(r>ri)ask(ver[r--]);
		while(l<li)ask(ver[l++]);
		int a=ver[l-1],b=ver[r];
		int c=lca(a,b);
		ask(c);
		ans[i]=act();
		ask(c);
	}
}

// add queries {st[a]+1, st[b]}
