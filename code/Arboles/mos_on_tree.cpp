const int maxn = 1e5+5;
const int maxq = 1e4+5;
vector<int> adj[maxn];
int ri[maxn],li[maxn],id[maxn*2],n,q,pos=0; 

void dfs(int v=0, int p=-1){
	id[pos]=v;
	ri[v]=pos++;
	for(int u:adj[v]){
		if(u==p)continue; 
		dfs(u,v);
	}
	id[pos]=v;
	li[v]=pos++;
}

int lca(int a, int b);
bool vis[maxn];ll act=0;

void add(int v, bool left);
void remove(int v, bool left);
void ask(int v, bool left){
	if(!vis[v])add(v, left);
	else remove(v, left);
	vis[v]=!vis[v];
}

int sqrtn;
struct query {
	int l, r, id;
	bool operator < (const query &x) const {
		if(l/sqrtn==x.l/sqrtn) return r<x.r;
		return l/sqrtn<x.l/sqrtn;
	}
};

query queries[maxq];ll ans[maxq];
void solve(){
	int l=0,r=-1;
	for(int i=0;i<q;++i){
		int L=queries[i].l,R=queries[i].r;
		if(R<l){
			while(l>L)ask(id[--l], true);
			while(l<L)ask(id[l++], true);
			while(r<R)ask(id[++r], false);
			while(r>R)ask(id[r--], false);
		}else{
			while(r<R)ask(id[++r], false);
			while(r>R)ask(id[r--], false);
			while(l>L)ask(id[--l], true);
			while(l<L)ask(id[l++], true);
		}
		int a=id[l],b=id[r],c=lca(a,b);
		// if(c!=b && c!=a)ask(c);
		ans[queries[i].id]=act;
		// if(c!=b && c!=a)ask(c);
	}
}

// memset(vis, 0, sizeof(vis));
// sqrtn=(int)ceil(sqrt(n));dfs();
// for(int u,v,i=0;i<q;++i){
// 	cin>>u>>v;u--;v--;
// 	if(ri[u]>ri[v])swap(u,v);
// 	int lc=lca(u,v);
// 	queries[i].l=(lc==u?ri[u]:li[u]);
// 	queries[i].r=ri[v];
// 	queries[i].id=i;
// }
// sort(queries, queries+q);
// solve();
