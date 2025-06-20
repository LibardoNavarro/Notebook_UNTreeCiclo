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
	void lazy(int len, ll _acum, ll _cnt){
		sum+=_acum*ll(len)+gauss(len)*_cnt;
		acum+=_acum;
		cnt+=_cnt;
	}
};
struct SegTree{
	vector<Node> vals;
	Node null;
	int size;

	void propagate(int x, int lx, int rx){
		if(rx-lx==1)return;
		if(vals[x].cnt==0)return;
		int m=(rx+lx)/2;
		vals[2*x+1].lazy(m-lx, vals[x].acum, vals[x].cnt);
		vals[2*x+2].lazy(rx-m, vals[x].acum+ll(m-lx)*vals[x].cnt, vals[x].cnt);
		vals[x].acum=vals[x].cnt=0;
	}

	void upd(int l, int r, int x, int lx, int rx){
		if(rx<=l || r<=lx)return;
		if(l<=lx && rx<=r){
			vals[x].lazy(rx-lx,lx-l,1);
			return;
		}
		propagate(x,lx,rx);
		int m=(lx+rx)/2;
		upd(l,r,2*x+1,lx,m);
		upd(l,r,2*x+2,m,rx);
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
};