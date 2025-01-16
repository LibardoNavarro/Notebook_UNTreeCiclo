typedef long long T;
struct Node{T val;int l,r;};
struct SegTree{ 
	vector<Node> ns;
	vector<int> roots;
	T null=0;
	int act=0,size;

	T oper(T a, T b){return a+b;}
	SegTree(vector<T>& a, int n){
		size=n;
		roots.push_back(build(a, 0, size));
	}

	void update(int x){
		ns[x].val=oper(ns[ns[x].l].val, ns[ns[x].r].val);
	}

	int newNode(T x){
		Node tmp={x,-1,-1};
		ns.push_back(tmp);
		return act++;
	}

	int newNode(int l, int r){
		Node tmp={null,l,r};
		ns.push_back(tmp);
		update(act);
		return act++;
	}

	int build(vector<T>& a, int l, int r){
		if(r-l==1){return newNode(a[l]);}
		int m=(l+r)/2;
		return newNode(build(a, l, m),build(a, m, r));
	}

	int set(int x, int i, T v, int l, int r){
		if(r-l==1)return newNode(v);
		int m=(l+r)/2;
		if(i<m)return newNode(set(ns[x].l, i, v, l, m), ns[x].r);
		else return newNode(ns[x].l, set(ns[x].r, i, v, m, r));
	}

	T get(int x, int lx, int rx, int l, int r){
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return ns[x].val;
		int m=(lx+rx)/2;
		T v1=get(ns[x].l, lx, m, l, r);
		T v2=get(ns[x].r, m, rx, l, r);
		return oper(v1,v2);
	}
	
	T get(int l, int r, int time){return get(roots[time], 0, size, l, r+1);}
	void set(int i, T v, int time){roots.push_back(set(roots[time], i, v, 0, size));}
};
