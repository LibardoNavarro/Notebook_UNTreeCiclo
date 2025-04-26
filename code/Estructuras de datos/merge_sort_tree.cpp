// O(n*log(n)) build
// O(log(n)) get
typedef long long T;
struct SegTree{
	int size;
	vector<vector<T>> vals;

	void oper(int x){
		merge(all(vals[2*x+1]), all(vals[2*x+2]), back_inserter(vals[x]));
	}
	SegTree(vector<T>& a){
		size=1;
		while(size<sz(a))size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	void build(vector<T>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<sz(a))vals[x]={a[lx]};
			if(lx<(int)a.size()){
				vals[x]={a[lx]};
			}
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		oper(x);
	}
	
	int get(int l, int r,int val, int x, int lx, int rx){
		if(lx>=r || l>=rx)return 0;
		if(lx>=l && rx<=r){
			return vals[x].size()-distance(vals[x].begin(),upper_bound(all(vals[x]),val));
		}
		int m=(lx+rx)/2;
		int v1=get(l,r,val,2*x+1,lx,m);
		int v2=get(l,r,val,2*x+2,m,rx);
		return v1+v2;
	}

	int get(int l, int r,int val){return get(l,r+1,val,0,0,size);}
};
