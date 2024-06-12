struct Node{int sum,l,r,ptr,ptrl,ptrr;};
struct SegTree{ // q*log(n) memory
	vector<Node> vals;
	vi lazy;
	int null=0;

	void oper(int x){vals[x].sum=vals[vals[x].ptrl].sum+vals[vals[x].ptrr].sum;}
	void extends(int x){
		if(vals[x].r-vals[x].l==1)return;
		int m=vals[x].l+(vals[x].r-vals[x].l)/2;
		if(vals[x].ptrl==-1){
			vals[x].ptrl=vals.size();
			vals.push_back({0,vals[x].l,m,vals[x].ptrl,-1,-1});
			lazy.push_back(0);
		}
		if(vals[x].ptrr==-1){
			vals[x].ptrr=vals.size();
			vals.push_back({0,m,vals[x].r,vals[x].ptrr,-1,-1});
			lazy.push_back(0);
		}
	}

	void build(int n){
		vals.push_back({0,1,n+1,0,-1,-1});
		lazy.push_back(0);
	}

    void propagate(int x){
		if(vals[x].r-vals[x].l==1)return;
        if(lazy[x]==0)return;
		extends(x);
		int m=vals[x].l+(vals[x].r-vals[x].l)/2;
		lazy[vals[x].ptrl]=1;
		lazy[vals[x].ptrr]=1;
		vals[vals[x].ptrl].sum=(m-vals[x].l);
		vals[vals[x].ptrr].sum=(vals[x].r-m);
		lazy[x]=0;
    }

    void upd(int l, int r, int x){
        propagate(x);
		int lx=vals[x].l, rx=vals[x].r;
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            lazy[x]=1;
			vals[x].sum=(rx-lx);
            return;
        }
		extends(x);
		upd(l,r,vals[x].ptrl);
		upd(l,r,vals[x].ptrr);
		oper(x);
	}

	int get(int l, int r, int x){
        propagate(x);
		int lx=vals[x].l, rx=vals[x].r;
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x].sum;
		extends(x);
		int v1=get(l,r,vals[x].ptrl);
		int v2=get(l,r,vals[x].ptrr);
		return v1+v2;
	}

	void upd(int l, int r){upd(l,r+1,0);}
	int get(int l, int r){return get(l,r+1,0);}
};
