struct dsu{
	vi p,rank,h;
	int sets;
	dsu(int n){
		sets=n;
		p.assign(n,0);
		rank.assign(n,1);
		for(int i=0;i<n;++i)p[i]=i;
	}
	int get(int a){return (a==p[a]?a:get(p[a]));}
	void unite(int a, int b){
		a=get(a);b=get(b);
		if(a==b)return;
		if(rank[a]>rank[b])swap(a,b);
		rank[b]+=rank[a];
		h.push_back(a);
		p[a]=b;sets--;
	}
	void rollback(int x){
		int len=h.size();
		while(len>x){
			int a=h.back();
			h.pop_back();
			rank[p[a]]-=rank[a];
			p[a]=a;sets++;len--;
		}
	}
};

enum { ADD, DEL, QUERY };
struct Query{int type, u, v;};
struct DynCon{
	vector<Query> q;  
	dsu uf;vi mt;  
	map<pair<int,int>, int> prv;
	DynCon(int n): uf(n){}
	void add(int i, int j){
		if(i>j)swap(i, j);
		q.push_back({ADD, i, j}); 
		mt.push_back(-1);
		prv[{i,j}]=sz(q)-1;
	}
	void remove(int i, int j){
		if(i > j) swap(i, j);
		q.push_back({DEL, i, j});
		int pr=prv[{i, j}];
		mt[pr]=sz(q)-1;  
		mt.push_back(pr);
	}
	void query(){q.push_back({QUERY, -1, -1});mt.push_back(-1);}
	void process(){ // answers all queries in order
		if(!sz(q))return;
		for(int i=0;i<sz(q);++i){
			if(q[i].type==ADD && mt[i]<0)mt[i]=sz(q);
		}go(0, sz(q));
	}
	void go(int s, int e){
		if(s+1==e){
		if(q[s].type == QUERY)cout<<uf.sets<<"\n";
		return;
		}int k=sz(uf.h),m=(s+e)/2;
		for(int i=e-1;i>=m;--i){
		if(mt[i]>=0 && mt[i]<s)uf.unite(q[i].u, q[i].v);
		}go(s, m);  
		uf.rollback(k);
		for(int i=m-1;i>=s;--i){
		if(mt[i]>=e)uf.unite(q[i].u, q[i].v);
		}go(m, e);  
		uf.rollback(k);
	}
};
