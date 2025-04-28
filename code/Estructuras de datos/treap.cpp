// Treap => Binary Search Tree + Binary Heap
// 1. create a empty root (PTreap root=nullptr;)
// 2. Append the nodes in asc order
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
	Treap(T v){
		l=r=nullptr;
		prior=rng();
		val=v;sz=1;
	}
	~Treap(){
		delete l;
		delete r;
	}
};

typedef Treap* PTreap;
T cnt(PTreap x){return (!x?0:x->sz);}

// updates node with its children information
void pull(PTreap x){
	x->sz=cnt(x->l)+cnt(x->r)+1;
	if(x->l)x->l->dad=x;
	if(x->r)x->r->dad=x;
}

// O(log(n)) divide the treap in two parts
// [nodes value <= key], [nodes value > key]
pair<PTreap, PTreap> split(PTreap x, T key){
	if(!x)return {nullptr, nullptr};
	if(x->val>key){
		auto got=split(x->l, key);
		x->l=got.second;
		pull(x);
		return {got.first, x};
	}else{
		auto got=split(x->r, key);
		x->r=got.first;
		pull(x);
		return {x, got.second};
	}
}

// O(log(n)) merge two treap 
// if all values in treap x < all values in treap y
PTreap merge(PTreap x, PTreap y){
	if(!x)return y;
	if(!y)return x;
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

// O(n*log(n)) 
// Combine two treap into one
PTreap combine(PTreap x, PTreap y){
	if(!x)return y;
	if(!y)return x;
	if(x->prior<y->prior)swap(x, y);
	auto z=split(y, x->val);
	x->r=combine(x->r, z.second);
	x->l=combine(z.first, x->l);
	return x;
}

// O(log(n))
// return kth element - indexed 0
T kth(PTreap& x, int k){ 
	if(!x)return null;
	if(k==cnt(x->l))return x->val;
	if(k<cnt(x->l))return kth(x->l, k);
	return kth(x->r, k-cnt(x->l)-1);
}

// O(log(n))
// return {index, val}
pair<int, T> lower_bound(PTreap x, T key){ 
	if(!x)return {0, null};
	if(x->val<key){
		auto y=lower_bound(x->r, key);
		y.first+=cnt(x->l)+1;
		return y;
	}
	auto y=lower_bound(x->l, key);
	if(y.first==cnt(x->l))y.second=x->val;
	return y;
}

// O(n) print the treap
void dfs(PTreap x){
	if(!x)return;
	dfs(x->l);
	cout<<x->val<<" ";
	dfs(x->r);
}