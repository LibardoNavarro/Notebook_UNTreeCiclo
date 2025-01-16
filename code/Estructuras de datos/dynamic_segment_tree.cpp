typedef long long T;
T null=0, noVal=0;
T oper(T a, T b){return a+b;}
struct Node{
	T val,lz;
	int l,r;
	Node *pl,*pr;
	Node(int ll, int rr){
		val=null;lz=noVal;
		pl=pr=nullptr;
		l=ll;r=rr;
	}
	void update(){
		if(r-l==1)return;
		val=oper(pl->val, pr->val);
	}
	void update(T v){
		val+=((T)(r-l))*v;
		lz+=v;
	}
	void extends(){
		if(r-l!=1 && !pl){
			int m=(r+l)/2;
			pl=new Node(l, m);
			pr=new Node(m, r);
		}
	}
	void propagate(){
		if(r-l==1)return;
		if(lz==noVal)return;
		pl->update(lz);
		pr->update(lz);
		lz=noVal;
	}
};

typedef Node* PNode;
struct SegTree{
	PNode root;
	SegTree(int l, int r){root=new Node(l, r+1);}

	void upd(PNode x, int l, int r, T v){
		int lx=x->l,rx=x->r;
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
			x->update(v);
			return;
		}
		x->extends();
		x->propagate();
		upd(x->pl,l,r,v);
		upd(x->pr,l,r,v);
		x->update();
	}

	T get(PNode x, int l, int r){
		int lx=x->l,rx=x->r;
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return x->val;
		x->extends();
		x->propagate();
		T v1=get(x->pl,l,r);
		T v2=get(x->pr,l,r);
		return oper(v1,v2);
	}

	T get(int l, int r){return get(root,l,r+1);}
	void upd(int l, int r, T v){upd(root,l,r+1,v);}
};
