// Treap => Binary Search Tree + Binary Heap
// 1. create a empty root (PTreap root=nullptr;)
// 2. Append the nodes in order (left -> right)
// PTreap tmp=new Treap(x);
// root=merge(root, tmp);

typedef long long T;
typedef unsigned long long u64;
mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());

T null = 0;
struct Treap{
	Treap *l,*r,*dad; // left child, right child
	u64 prior; // random
	T sz,val; // size subtree, value
	T sum,lz; // sum subtree, lazy
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

void update_helper(PTreap x, T v){
    // lz += v
    // val += v
    // sum += v
}

// propagate the lazy
void push(PTreap x){
	if(x && x->lz){ // check x->lz
		if(x->l)update_helper(x->l, 1);
		if(x->r)update_helper(x->r, 1);
		x->lz=0;
	}
}

// updates node with its children information
void pull(PTreap x){
	push(x->l);
	push(x->r);
	x->sz=cnt(x->l)+cnt(x->r)+1;
	x->sum=sum(x->l)+sum(x->r)+x->val;
	if(x->l)x->l->dad=x;
	if(x->r)x->r->dad=x;
}

// Updates node value += v
void upd(PTreap x, T v){
	if(!x)return;
	pull(x);
    update_helper(x,v);
}

// O(log(n)) divide the treap in two parts
// [count nodes == left], [the rest of nodes]
pair<PTreap, PTreap> split(PTreap x, int left){ 
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

// O(log(n)) merge two treap 
// [nodes treap x ... nodes treap y]
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

// O(n) print the treap
void dfs(PTreap x){
	if(!x)return;
	push(x);
	dfs(x->l);
	cout<<x->val<<" ";
	dfs(x->r);
}