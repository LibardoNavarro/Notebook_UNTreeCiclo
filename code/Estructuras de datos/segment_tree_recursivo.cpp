typedef long long T;
struct SegTree{
	vector<T> vals,lazy;
	T null=0,noVal=0;
	int size;
	T oper(T a, T b);
	void build(vector<T>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<sz(a))vals[x]=a[lx];
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}
	void build(vector<T>& a,int n){
		size=1;
		while(size<n)size*=2;
		vals.resize(2*size);
		lazy.assign(2*size, noVal);
		build(a, 0, 0, size);
	}
	void propagate(int x, int lx, int rx){
		if(rx-lx==1)return;
		if(lazy[x]==noVal)return;
		int m=(lx+rx)/2;
		// 2*x+1, 2*x+2 (lazy, vals)
		lazy[x]=noVal;
	}
	void upd(int l, int r, T v,int x, int lx, int rx){
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
			// lazy, vals
			return;
		}
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		upd(l,r,v,2*x+1,lx,m);
		upd(l,r,v,2*x+2,m,rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}
	void set(int i, T v, int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]=v;
			return;
		}
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		if(i<m)set(i,v,2*x+1,lx,m);
		else set(i,v,2*x+2,m,rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}
	T get(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x];
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		T v1=get(l,r,2*x+1,lx,m);
		T v2=get(l,r,2*x+2,m,rx);
		return oper(v1,v2);
	}
	T get(int l, int r){return get(l,r+1,0,0,size);}
	void upd(int l, int r, T v){upd(l,r+1,v,0,0,size);}
	void set(int i, T val){set(i,val,0,0,size);}
};