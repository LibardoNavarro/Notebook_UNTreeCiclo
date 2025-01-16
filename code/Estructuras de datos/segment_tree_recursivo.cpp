typedef long long T;
struct SegTree{
	vector<T> vals,lazy;
	T null=0,nolz=0;
	int size;

	T op(T a, T b){return a+b;}
	SegTree(vector<T>& a,int n){
		size=1;
		while(size<n)size*=2;
		vals.resize(2*size);
		lazy.assign(2*size, nolz);
		build(a, 0, 0, size);
	}

	void build(vector<T>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<sz(a))vals[x]=a[lx];
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		vals[x]=op(vals[2*x+1], vals[2*x+2]);
	}

	void propagate(int x, int lx, int rx){
		if(rx-lx==1)return;
		if(lazy[x]==nolz)return;
		int m=(lx+rx)/2;
		lazy[2*x+1]+=lazy[x];
		vals[2*x+1]+=lazy[x]*((T)(m-lx));
		lazy[2*x+2]+=lazy[x]; 
		vals[2*x+2]+=lazy[x]*((T)(rx-m));
		lazy[x]=nolz;
	}

	void upd(int l, int r, T v,int x, int lx, int rx){
		if(rx<=l || r<=lx)return;
		if(l<=lx && rx<=r){
			lazy[x]+=v;
			vals[x]+=v*((T)(rx-lx));
			return;
		}
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		upd(l,r,v,2*x+1,lx,m);
		upd(l,r,v,2*x+2,m,rx);
		vals[x]=op(vals[2*x+1], vals[2*x+2]);
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
		vals[x]=op(vals[2*x+1], vals[2*x+2]);
	}

	T get(int l, int r, int x, int lx, int rx){
		if(rx<=l || r<=lx)return null;
		if(l<=lx && rx<=r)return vals[x];
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		T v1=get(l,r,2*x+1,lx,m);
		T v2=get(l,r,2*x+2,m,rx);
		return op(v1,v2);
	}

	T get(int l, int r){return get(l,r+1,0,0,size);}
	void upd(int l, int r, T v){upd(l,r+1,v,0,0,size);}
	void set(int i, T val){set(i,val,0,0,size);}
};
