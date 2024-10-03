ll null=LLONG_MIN;
ll oper(ll a, ll b){return max(a,b);}
// segtree build, set, upd, get

const int maxn=1e5+1; 
bool VALS_IN_EDGES=false; // arista padre
struct HLD{
	int par[maxn], root[maxn], dep[maxn];
	int sz[maxn], pos[maxn], ti;
	vi adj[maxn];
	SegTree st;
	void addEdge(int x, int y){adj[x].push_back(y);adj[y].push_back(x);}
	void dfsSz(int x){ 
		sz[x]=0; 
		for(int& y:adj[x]){
			if(y==par[x])continue;
			par[y]=x;dep[y]=dep[x]+1;
			dfsSz(y); 
			sz[x]+=sz[y]+1;
			if(sz[y]>sz[adj[x][0]])swap(y,adj[x][0]);
		}
	}
	void dfsHld(int x){
		pos[x]=ti++;
		for(int y:adj[x]){
		if(y==par[x])continue;
		root[y]=(y==adj[x][0]?root[x]:y);
		dfsHld(y);
		}
	}
	void build(int n,int v=0){ 
		root[v]=par[v]=v;
		dep[v]=ti=0; 
		dfsSz(v); 
		dfsHld(v);
		// vl palst(n);
		// for(int i=0;i<n;++i)palst[pos[i]]=a[i];
		// st.build(palst, n);
		st.build(n);
	}
	template <class Oper>
	void processPath(int x, int y, Oper op){
		for(;root[x]!=root[y];y=par[root[y]]){
			if(dep[root[x]]>dep[root[y]])swap(x,y);
			op(pos[root[y]],pos[y]); 
		}
		if(dep[x]>dep[y])swap(x,y);
		op(pos[x]+VALS_IN_EDGES,pos[y]); 
	}
	void modifyPath(int x, int y, int v){ 
		processPath(x,y,[this,&v](int l, int r){ 
			st.upd(l,r,v);
		}); 
	}
	ll queryPath(int x, int y){ 
		ll res=null;
		processPath(x,y,[this,&res](int l, int r){ 
			res=oper(res, st.get(l,r));
		});
		return res; 
	}
	void modifySubtree(int x, int v){st.upd(pos[x]+VALS_IN_EDGES,pos[x]+sz[x],v);}
	int querySubtree(int x){return st.get(pos[x]+VALS_IN_EDGES,pos[x]+sz[x]);}
	void modify(int x, int v){st.set(pos[x],v);} 
	void modifyEdge(int x, int y, int v){
		if(dep[x]<dep[y])swap(x,y);
		modify(x,v);
	}
};
