ll gauss(ll x){return (x*(x+1ll))/2ll;}
struct Node{
	ll sum=0; // the nodes value
	ll acum=0; //  count completed levels
	ll cnt=0; // count of updates +1, +2, +3, ...
	void build(ll v){
		acum=cnt=0;
		sum=v;
	}
	void oper(Node& a, Node& b){
		sum=a.sum+b.sum;
		acum=cnt=0;
	}
	void lazy(ll len, ll _acum, ll _cnt){
		sum+=_acum*len+gauss(len)*_cnt;
		acum+=_acum;
		cnt+=_cnt;
	}
};
struct SegTree{
	vector<Node> vals;
	Node null;
	int size;

	SegTree(vector<ll>& a){
		size=1;
		while(size<sz(a))size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	void build(vector<ll>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<sz(a))vals[x].build(a[lx]);
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		vals[x].oper(vals[2*x+1], vals[2*x+2]);
	}

	void propagate(int x, int lx, int rx){
		if(rx-lx==1)return;
		if(vals[x].cnt==0)return;
		int m=(rx+lx)/2;
		vals[2*x+1].lazy(m-lx, vals[x].acum, vals[x].cnt);
		vals[2*x+2].lazy(rx-m, vals[x].acum+ll(m-lx)*vals[x].cnt, vals[x].cnt);
		vals[x].acum=vals[x].cnt=0;
	}

	void upd(int l, int r, ll v, int x, int lx, int rx){
		if(rx<=l || r<=lx)return;
		if(l<=lx && rx<=r){
			vals[x].lazy(rx-lx,v*(lx-l),v);
			return;
		}
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		upd(l,r,v,2*x+1,lx,m);
		upd(l,r,v,2*x+2,m,rx);
		vals[x].oper(vals[2*x+1], vals[2*x+2]);
	}

	ll get(int l, int r, int x, int lx, int rx){
		if(rx<=l || r<=lx)return null.sum;
		if(l<=lx && rx<=r)return vals[x].sum;
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		ll v1=get(l,r,2*x+1,lx,m);
		ll v2=get(l,r,2*x+2,m,rx);
		return v1+v2;
	}

	ll get(int l, int r){return get(l,r+1,0,0,size);}
	void upd(int l, int r, ll v){upd(l,r+1,v,0,0,size);} 
	// v es la cantidad de veces que se aplica la operacion +1, +2, +3
};