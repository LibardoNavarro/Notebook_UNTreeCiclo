typedef pair<int, int> ii;
struct DSU {
	vector<int> p,size,h;
	int sets;
	void build(int n){
		sets=n;
		p.assign(n,0);
		size.assign(n,1);
		for(int i=0;i<n;++i)p[i]=i;
	}
	int get(int a){return (a==p[a]?a:get(p[a]));} 
	void unite(int a, int b){
		a=get(a);b=get(b);
		if(a==b)return;
		if(size[a]>size[b])swap(a,b);
		h.push_back(a);
		size[b]+=size[a];
		p[a]=b;sets--;
	}
	void rollback(int s){
		while(sz(h)>s){
			int a=h.back();
			h.pop_back();
			size[p[a]]-=size[a];
			p[a]=a;sets++;
		}
	}
};

// O(q*log(q)*log(n))
enum { ADD, DEL, QUERY };
struct Query { int type,u,v; };
struct DynCon {
	map<ii, int> edges;DSU uf;
	vector<Query> q;
	vector<int> t;
	void add(int u, int v){
		if(u>v)swap(u,v);
		edges[{u,v}]=sz(q);
		q.push_back({ADD, u, v});
		t.push_back(-1);
	}
	void del(int u, int v){
		if(u>v)swap(u,v);
		int i=edges[{u,v}];
		t[i]=sz(q);
		q.push_back({DEL, u, v});
		t.push_back(i);
	}
	void query(){
		q.push_back({QUERY, -1, -1});
		t.push_back(-1);
	}
	void dnc(int l, int r){
		if(r-l==1){
			if(q[l].type==QUERY)
				cout<<uf.sets<<"\n";
			return;
		}
		int m=l+(r-l)/2,k=sz(uf.h);
		for(int i=m;i<r;++i)
			if(q[i].type==DEL && t[i]<l)
				uf.unite(q[i].u, q[i].v);
		dnc(l, m);
		uf.rollback(k);
		for(int i=l;i<m;++i)
			if(q[i].type==ADD && t[i]>=r)
				uf.unite(q[i].u, q[i].v);
		dnc(m, r);
		uf.rollback(k);
	}
	void init(int n){
		uf.build(n);
		if(!sz(q))return;
		for(int& ti:t)if(ti==-1)ti=sz(q);
		dnc(0, sz(q));
	}
};