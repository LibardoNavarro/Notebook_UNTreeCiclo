ll sum(ll x){return (x*(x+1ll))/2ll;}
struct Node{
	ll sum; // the nodes value
	ll acum; //  count completed levels
	ll cnt; // count of updates +1, +2, +3, ...
};

// check the null, oper, single, upd(l,r) remove the third parameter
...

vector<Node> vals;

void lazy(int x, int len, ll acum, ll cnt){
	vals[x].sum+=acum*ll(len)+sum(len)*cnt;
	vals[x].acum+=acum;
	vals[x].cnt+=cnt;
}

void propagate(...){
	if(rx-lx==1)return;
	if(vals[x].cnt==0)return;
	int m=(rx+lx)/2;
	lazy(2*x+1, m-lx, vals[x].acum, vals[x].cnt);
	lazy(2*x+2, rx-m, vals[x].acum+ll(m-lx)*vals[x].cnt, vals[x].cnt);
	vals[x].acum=vals[x].cnt=0;
}

void upd(int l, int r, ...){
	if(l<=lx && rx<=r){
		lazy(x,rx-lx,lx-l,1);
		return;
	}
}
