T null=0,noVal=0;
T oper(T a, T b);
struct Node{
	T val,lz;
	int l,r;
	Node *pl,*pr;
	Node(int ll, int rr){
		val=null;lz=noVal;
		pl=pr=nullptr;
		l=ll;r=rr;
	}
};

typedef Node* PNode;
void update(PNode x){
	if(x->r-x->l==1)return;
	x->val=oper(x->pl->val,x->pr->val);
}

void extends(PNode x){
	if(x->r-x->l!=1 && !x->pl){
		int m=(x->r+x->l)/2;
		x->pl=new Node(x->l, m);
		x->pr=new Node(m, x->r);
	}
}

void propagate(PNode x){
	if(x->r-x->l==1)return;
	if(x->lz==noVal)return;
	int m=(x->r+x->l)/2;
	// pl, pr
	x->lz=noVal;
}

struct SegTree{
	PNode root;
	void upd(PNode x, int l, int r, T v){
		int lx=x->l,rx=x->r;
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
			// val, lz
			return;
		}
		extends(x);
		propagate(x);
		upd(x->pl,l,r,v);
		upd(x->pr,l,r,v);
		update(x);
	}

	T get(PNode x, int l, int r){
		int lx=x->l,rx=x->r;
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return x->val;
		extends(x);
		propagate(x);
		T v1=get(x->pl,l,r);
		T v2=get(x->pr,l,r);
		return oper(v1,v2);
	}

	T get(int l, int r){return get(root,l,r+1);}
	void upd(int l, int r, T v){upd(root,l,r+1,v);}
	void build(int l, int r){root=new Node(l, r+1);}
};
