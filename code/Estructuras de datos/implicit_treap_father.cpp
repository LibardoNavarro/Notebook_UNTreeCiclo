// Treap => Binary Search Tree + Binary Heap
// 1. create a empty root (PTreap root=nullptr;)
// 2. Append the nodes in order (left -> right)
// PTreap tmp=new Treap(x);
// root=merge(root, tmp);

// si se edita un treap, se tiene que hacer un pullAll hasta la raiz
// si no se hace esto, el treap queda con informacion pasada

// si se va a modificar un treap, hacer un pushAll para bajar los lazy

typedef long long T;
typedef unsigned long long u64;
mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());

T null = 0;
struct Treap{
	Treap *l,*r,*dad; // left child, right child
	u64 prior; // random
	T val,sum; // value, sum subtree
	int sz; // size subtree
	Treap(T v){
		l=r=dad=nullptr;
		prior=rng();
		val=sum=v;
		sz=1;
	}
	~Treap(){
		delete l;
		delete r;
	}
};

typedef Treap* PTreap;
int cnt(PTreap x){return (!x?0:x->sz);}
T sum(PTreap x){return (!x?0:x->sum);}

// updates node with its children information
void pull(PTreap x){
	x->sz=cnt(x->l)+cnt(x->r)+1;
	x->sum=sum(x->l)+sum(x->r)+x->val;
	if(x->l)x->l->dad=x; //
	if(x->r)x->r->dad=x; //
}

// O(log(n)) divide the treap in two parts
// [count nodes == left], [the rest of nodes]
pair<PTreap, PTreap> split(PTreap x, int left){ 
	if(!x)return {nullptr, nullptr};
	if(cnt(x->l)>=left){ 
		auto got=split(x->l, left); 
		if(got.first)got.first->dad=nullptr; //
		x->l=got.second;
		x->dad=nullptr; //
		pull(x);
		return {got.first, x};
	}else{
		auto got=split(x->r, left-cnt(x->l)-1);
		if(got.second)got.second->dad=nullptr; //
		x->r=got.first;
		x->dad=nullptr; //
		pull(x);
		return {x, got.second};
	}
}

// O(log(n)) merge two treap 
// [nodes treap x ... nodes treap y]
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

// O(log(n)) propagate the lazy [root->x]
void pushAll(PTreap x){
	if(!x)return;
	pushAll(x->dad);
	push(x);
}

// O(log(n)) update the treap [root->x]
void pullAll(PTreap x){
	if(!x)return;
	pull(x);
	pullAll(x->dad);
}

// O(log(n)) return the root and the position of x (1-indexed)
pair<PTreap, int> findRoot(PTreap x){
	pushAll(x);
	int pos=cnt(x->l);
	while(x->dad){
		PTreap f=x->dad;
		if(x==f->r)pos+=cnt(f->l)+1;
		x=f;
	}
	return {x,pos+1};
}
