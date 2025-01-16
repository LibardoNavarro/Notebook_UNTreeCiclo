typedef long long T;
// build O(n) - get O(n/b+b)
struct SQRT{ 
	int b; // check b
	vector<T> a,bls;
	SQRT(vector<T>& arr, int n){
		b=ceil(sqrt(n));a=arr;
		bls.assign(b, 0);
		for(int i=0;i<n;++i){
			bls[i/b]+=a[i];
		}
	}

	void set(int x, int v){
		bls[x/b]-=a[x];
		a[x]=v;
		bls[x/b]+=a[x];
	}

	T get(int r){
		T res=0;
		for(int i=0;i<r/b;++i){res+=bls[i];}
		for(int i=(r/b)*b;i<r;++i){res+=a[i];}
		return res;
	}

	T get(int l, int r){return get(r+1)-get(l);}
};
