typedef long long T;
typedef unsigned long long u64;
mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());

T null = 0;
struct Treap{
	Treap *l,*r,*dad;
	u64 prior;
	T sz,val,sum,lz;
	Treap(T v){
		l=r=nullptr;
		prior=rng();
		val=sum=v;
		lz=0;sz=1;
	}
	~Treap(){
		delete l;
		delete r;
	}
};

typedef Treap* PTreap;
T cnt(PTreap x){return (!x?0:x->sz);}
T sum(PTreap x){return (!x?0:x->sum);}

void update(PTreap x, T v){
	// lz, val, sum ...
}

void push(PTreap x){
	if(x && x->lz){
		if(x->l)update(x->l, 1);
		if(x->r)update(x->r, 1);
		x->lz=0;
	}
}

void pull(PTreap x){
	push(x->l);
	push(x->r);
	x->sz=cnt(x->l)+cnt(x->r)+1;
	x->sum=sum(x->l)+sum(x->r)+x->val;
	if(x->l)x->l->dad=x;
	if(x->r)x->r->dad=x;
}

void upd(PTreap x, T v){
	if(!x)return;
	pull(x);
	update(x,v);
}

pair<PTreap, PTreap> split(PTreap x, int left){ // cnt(f) == left
	if(!x)return {nullptr, nullptr};
	push(x);
	if(cnt(x->l)>=left){ 
		auto got=split(x->l, left); 
		x->l=got.second;
		pull(x);
		return {got.first, x};
	}else{
		auto got=split(x->r, left-cnt(x->l)-1);
		x->r=got.first;
		pull(x);
		return {x, got.second};
	}
}

PTreap merge(PTreap x, PTreap y){
	if(!x)return y;
	if(!y)return x;
	push(x);push(y);
	if(x->prior<=y->prior){
		x->r=merge(x->r, y);
		pull(x);
		return x;
	}else{
		y->l=merge(x, y->l);
		pull(y);
		return y;
	}
}

void dfs(PTreap x){
	if(!x)return;
	push(x);
	dfs(x->l);
	cout<<x->val<<" ";
	dfs(x->r);
}

PTreap root=nullptr;
PTreap tmp=new Treap(x);
root=merge(root, tmp);
