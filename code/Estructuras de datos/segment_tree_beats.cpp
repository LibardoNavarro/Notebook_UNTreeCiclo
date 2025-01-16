typedef long long T;
T null=0,noVal=0;
T INF=1e18;
struct Node{
	T sum,lazy;
	T max1,max2,maxc;
	T min1,min2,minc;
};
struct SegTree{
	vector<Node> vals;
	int size;

	void oper(int a, int b, int c); // node c, left a, right b;
	Node single(T x){
		Node tmp;
		tmp.sum=tmp.max1=tmp.min1=x;
		tmp.maxc=tmp.minc=1;
		tmp.lazy=noVal;
		tmp.max2=-INF;
		tmp.min2=INF;
		return tmp;
	}

	void build(vector<T>& a,int n);
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
		oper(2*x+1, 2*x+2, x);
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
		oper(2*x+1, 2*x+2, x);
	}

	void updAdd(int l, int r, T v){updAdd(l,r+1,v,0,0,size);}
	void updMin(int l, int r, T v){updMin(l,r+1,v,0,0,size);}
};
