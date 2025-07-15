const int maxn = 1e5+5;
const int maxv = 1e9;
const int minv = -1e9; 

// O(n*log(n)) build
// O(log(n)) kth, lte, cnt, sum
// 1. int a[maxn];
// 2. WaveletTree wt;
// 3. fill a[1;n]
// 4. wt.build(a+1, a+n+1, minv, maxv);
struct WaveletTree { // indexed 1
	int lo, hi;
	WaveletTree *l, *r;
	int *b, bsz, csz;
	ll *c;

	WaveletTree() {
		hi=bsz=csz=0;
		l=r=NULL;
		lo=1;
	}

	void build(int *from, int *to, int x, int y){
		lo=x,hi=y;
		if(from>=to)return;
		int mid=lo+(hi-lo)/2;
		auto f=[mid](int x){return x<=mid;};
		b=(int*)malloc((to-from+2)*sizeof(int));
		bsz=0;
		b[bsz++]=0;
		c=(ll*)malloc((to-from+2)*sizeof(ll));
		csz=0;
		c[csz++]=0;
		for(auto it=from;it!=to;++it){
			b[bsz]=(b[bsz-1]+f(*it));
			c[csz]=(c[csz-1]+(*it));
			bsz++;csz++;
		}
		if(hi==lo)return;
		auto pivot=stable_partition(from, to, f);
		l=new WaveletTree();
		l->build(from, pivot, lo, mid);
		r=new WaveletTree();
		r->build(pivot, to, mid+1, hi);
	}

	//kth smallest element in [l, r]
	int kth(int l, int r, int k){
		if(l>r)return 0;
		if(lo==hi)return lo;
		int inLeft=b[r]-b[l-1], lb=b[l-1], rb=b[r];
		if(k<=inLeft)return this->l->kth(lb+1, rb, k);
		return this->r->kth(l-lb, r-rb, k-inLeft);
	}
	
	//count of numbers in [l, r] Less than or equal to k
	int lte(int l, int r, int k){
		if(l>r || k<lo)return 0;
		if(hi<=k)return r-l+1;
		int lb=b[l-1], rb=b[r];
		return this->l->lte(lb+1, rb, k)+this->r->lte(l-lb, r-rb, k);
	}

	//count of numbers in [l, r] equal to k
	int count(int l, int r, int k){
		if(l>r || k<lo || k>hi)return 0;
		if(lo==hi)return r-l+1;
		int lb=b[l-1], rb=b[r];
		int mid=(lo+hi)>>1;
		if(k<=mid)return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k);
	}

	//sum of numbers in [l ,r] less than or equal to k
	ll sum(int l, int r, int k){
		if(l>r || k<lo)return 0;
		if(hi<=k)return c[r]-c[l-1];
		int lb=b[l-1], rb=b[r];
		return this->l->sum(lb+1, rb, k)+this->r->sum(l-lb, r-rb, k);
	}

	~WaveletTree(){
		delete l;
		delete r;
	}
};

