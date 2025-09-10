typedef long long T;
T oper(T a, T b){return max(a,b);}
T null=-1e18;
struct SegTree{}; // Add Segment tree

// O(nlog(n)) build
// O(log(n)^2) (query - update) path
// O(log(n)) (query - update) subtree, node

// 1) call build(adj,n,root)
struct HLD{
	SegTree st;
	vector<vi> adj;
	vi dad,root,dep,sz,pos;
	int time;
	bool edges=false; // if the values are on edges instead of nodes

	void build(vector<vi>& adj2, int n, int v=0){ // v is the root
		adj=adj2;
		dad.resize(n);
		root.resize(n);
		dep.resize(n);
		sz.resize(n);
		pos.resize(n);

		root[v]=dad[v]=v;
		dep[v]=time=0; 

		dfsSz(v); 
		dfsHld(v);
		// vector<T> palst(n);
		// for(int i=0;i<n;++i)palst[pos[i]]=vals[i];
		// st.build(palst);
		st.build(n);
	}

	void dfsSz(int x){ 
		sz[x]=0; 
		for(int& y:adj[x]){
			if(y==dad[x])continue;
			dad[y]=x;dep[y]=dep[x]+1;
			dfsSz(y); 
			sz[x]+=sz[y]+1;
			if(sz[y]>sz[adj[x][0]])swap(y,adj[x][0]);
		}
	}

	void dfsHld(int x){
		pos[x]=time++;
		for(int y:adj[x]){
			if(y==dad[x])continue;
			root[y]=(y==adj[x][0]?root[x]:y);
			dfsHld(y);
		}
	}

	// O(log(n)^2)
	template <class Oper> 
	void processPath(int x, int y, Oper op){
		for(;root[x]!=root[y];y=dad[root[y]]){
			if(dep[root[x]]>dep[root[y]])swap(x,y);
			op(pos[root[y]],pos[y]); 
		}
		if(dep[x]>dep[y])swap(x,y);
		op(pos[x]+edges,pos[y]); 
	}

	void modifyPath(int x, int y, int v){ 
		processPath(x,y,[this,&v](int l, int r){ 
			st.upd(l,r,v);
		}); 
	}

	T queryPath(int x, int y){ 
		T res=null;
		processPath(x,y,[this,&res](int l, int r){ 
			res=oper(res, st.get(l,r));
		});
		return res; 
	}

	// O(log(n))
	void modifySubtree(int x, int v){
		st.upd(pos[x]+edges,pos[x]+sz[x],v);
	}

	T querySubtree(int x){
		return st.get(pos[x]+edges,pos[x]+sz[x]);
	}
	
	void modify(int x, int v){st.set(pos[x],v);} 
	void modifyEdge(int x, int y, int v){
		if(dep[x]<dep[y])swap(x,y);
		modify(x,v);
	}
};