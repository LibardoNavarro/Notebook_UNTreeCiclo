// O(n*log(n)) build
// O(log(n)) get, upd
// updMax[l,r] -> ai = max(ai, v)
// updMin[l,r] -> ai = min(ai, v)
// updAdd[l,r] -> ai = ai + v
// get[l,r] -> return sum of the range [l,r]
typedef long long T;
T null=0,noVal=0;
T INF=1e18;
struct Node{
	T sum,lazy;
	T max1,max2,maxc;
	T min1,min2,minc;

	void build(T x){
		sum=max1=min1=x;
		maxc=minc=1;
		lazy=noVal;
		max2=-INF;
		min2=INF;
	}

	void oper(Node& a, Node& b){
		sum=a.sum+b.sum;

		if(a.max1>b.max1){
			max1=a.max1;
			maxc=a.maxc;
			max2=max(a.max2, b.max1);
		}else if(a.max1<b.max1){
			max1=b.max1;
			maxc=b.maxc;
			max2=max(b.max2, a.max1);
		}else{
			max1=a.max1;
			maxc=a.maxc+b.maxc;
			max2=max(a.max2, b.max2);
		}

		if(a.min1<b.min1){
			min1=a.min1;
			minc=a.minc;
			min2=min(a.min2, b.min1);
		}else if(a.min1>b.min1){
			min1=b.min1;
			minc=b.minc;
			min2=min(b.min2, a.min1);
		}else{
			min1=a.min1;
			minc=a.minc+b.minc;
			min2=min(a.min2, b.min2);
		}
	}
};
struct SegTree{
	vector<Node> vals;
	int size;

	SegTree(vector<T>& a){
		size=1;
		while(size<sz(a))size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	void build(vector<T>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<sz(a))vals[x].build(a[lx]);
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		vals[x].oper(vals[2*x+1], vals[2*x+2]);
	}

	void propagateMax(T v, int x, int lx, int rx){
		if(vals[x].min1>=v)return;
		vals[x].sum-=vals[x].min1*vals[x].minc;
		vals[x].min1=v;
		vals[x].sum+=vals[x].min1*vals[x].minc;
		if(rx-lx==1){
			vals[x].max1=v;
		}else{
			if(v>=vals[x].max1){
				vals[x].max1=v;
			}else if(v>vals[x].max2){
				vals[x].max2=v;
			}
		}
	}

	void propagateMin(T v, int x, int lx, int rx){
		if(vals[x].max1<=v)return;
		vals[x].sum-=vals[x].max1*vals[x].maxc;
		vals[x].max1=v;
		vals[x].sum+=vals[x].max1*vals[x].maxc;
		if(rx-lx==1){
			vals[x].min1=v;
		}else{
			if(v<=vals[x].min1){
				vals[x].min1=v;
			}else if(v<vals[x].min2){
				vals[x].min2=v;
			}
		}
	}

	void propagateAdd(T v, int x, int lx, int rx){
		vals[x].sum+=v*((T)(rx-lx));
		vals[x].lazy+=v;
		vals[x].max1+=v;
		vals[x].min1+=v;
		if(vals[x].max2!=-INF)vals[x].max2+=v;
		if(vals[x].min2!=INF)vals[x].min2+=v;
	}

	void propagate(int x, int lx, int rx){
		if(rx-lx==1)return;
		int m=(lx+rx)/2;
		if(vals[x].lazy!=noVal){
			propagateAdd(vals[x].lazy, 2*x+1, lx, m);
			propagateAdd(vals[x].lazy, 2*x+2, m, rx);
			vals[x].lazy=noVal;
		}
		
		propagateMin(vals[x].max1, 2*x+1, lx, m);
		propagateMin(vals[x].max1, 2*x+2, m, rx);

		propagateMax(vals[x].min1, 2*x+1, lx, m);
		propagateMax(vals[x].min1, 2*x+2, m, rx);
	}

	void updAdd(int l, int r, T v,int x, int lx, int rx){
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
			propagateAdd(v, x, lx, rx);
			return;
		}
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		updAdd(l,r,v,2*x+1,lx,m);
		updAdd(l,r,v,2*x+2,m,rx);
		vals[x].oper(vals[2*x+1], vals[2*x+2]);
	}

	void updMax(int l, int r, T v,int x, int lx, int rx){
		if(lx>=r || l>=rx || vals[x].min1>v)return;
		if(lx>=l && rx<=r && vals[x].min2>v){
			propagateMax(v, x, lx, rx);
			return;
		}
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		updMax(l,r,v,2*x+1,lx,m);
		updMax(l,r,v,2*x+2,m,rx);
		vals[x].oper(vals[2*x+1], vals[2*x+2]);
	}

	void updMin(int l, int r, T v,int x, int lx, int rx){
		if(lx>=r || l>=rx || vals[x].max1<v)return;
		if(lx>=l && rx<=r && vals[x].max2<v){
			propagateMin(v, x, lx, rx);
			return;
		}
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		updMin(l,r,v,2*x+1,lx,m);
		updMin(l,r,v,2*x+2,m,rx);
		vals[x].oper(vals[2*x+1], vals[2*x+2]);
	}

	T get(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x].sum;
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		T v1=get(l,r,2*x+1,lx,m);
		T v2=get(l,r,2*x+2,m,rx);
		return v1+v2;
	}

	T get(int l, int r){return get(l,r+1,0,0,size);}
	void updAdd(int l, int r, T v){updAdd(l,r+1,v,0,0,size);}
	void updMin(int l, int r, T v){updMin(l,r+1,v,0,0,size);}
	void updMax(int l, int r, T v){updMax(l,r+1,v,0,0,size);}
};