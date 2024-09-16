typedef long long T;
typedef unsigned long long u64;
mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());

// T null = ;
// treap => order asc, implicit treap => order array
struct Treap{
	Treap *l,*r,*dad;
	u64 prior;
	T sz,value,sum,lz;
	Treap(T v){
		l=r=nullptr;
		lz=0;
		prior=rng();
		sz=1;
		value=sum=v;
	}

	~Treap(){
		delete l;
		delete r;
	}
};

typedef Treap* PTreap;
T cnt(PTreap x){return (!x?0:x->sz);}
T sum(PTreap x){return (!x?0:x->sum);}

void propagate(PTreap x){
	if(x && x->lz){
		if(x->l); // lz, value, sum ...
		if(x->r); // lz, value, sum ...
		x->lz=0;
	}
}

void update(PTreap x){
	propagate(x->l);
	propagate(x->r);
	x->sz=cnt(x->l)+cnt(x->r)+1;
	x->sum=sum(x->l)+sum(x->r)+x->value;
	if(x->l)x->l->dad=x;
	if(x->r)x->r->dad=x;
}

void upd(PTreap x, T v){
	if(!x)return;
	update(x);
	// lz, value, sum ...
}

// pair<PTreap, PTreap> split(PTreap x, T key){ // f <= key < s
pair<PTreap, PTreap> split(PTreap x, int left){ // cnt(f) == left
	if(!x)return {nullptr, nullptr};
	propagate(x);
	if(cnt(x->l)>=left){ // if(x->value>key){
		auto got=split(x->l, left); // , key);
		x->l=got.second;
		update(x);
		return {got.first, x};
	}else{
		auto got=split(x->r, left-cnt(x->l)-1); // , key);
		x->r=got.first;
		update(x);
		return {x, got.second};
	}
}

PTreap merge(PTreap x, PTreap y){
	if(!x)return y;
	if(!y)return x;
	propagate(x);
	propagate(y);
	if(x->prior<=y->prior){
		x->r=merge(x->r, y);
		update(x);
		return x;
	}else{
		y->l=merge(x, y->l);
		update(y);
		return y;
	}
}

PTreap combine(PTreap x, PTreap y){
	if(!x)return y;
	if(!y)return x;
	if(x->prior<y->prior)swap(x, y);
	auto z=split(y, x->value);
	x->r=combine(x->r, z.second);
	x->l=combine(z.first, x->l);
	return x;
}

T kth(PTreap& x, int k){ // indexed 0
	if(!x)return null;
	if(k==cnt(x->l))return x->value;
	if(k<cnt(x->l))return kth(x->l, k);
	return kth(x->r, k-cnt(x->l)-1);
}

pair<int, T> lower_bound(PTreap x, T key){ // index, value
	if(!x)return {0, null};
	if(x->value<key){
		auto y=lower_bound(x->r, key);
		y.first+=cnt(x->l)+1;
		return y;
	}
	auto y=lower_bound(x->l, key);
	if(y.first==cnt(x->l))y.second=x->value;
	return y;
}

void dfs(PTreap x){
	if(!x)return;
	propagate(x);
	dfs(x->l);
	cout<<x->value<<" ";
	dfs(x->r);
}

// PTreap root=nullptr;
// PTreap act=new Treap(c);
// root=merge(root, act);
