// O(n) build
// O(log(n)) get, upd
typedef long long T;
struct BIT{
	vector<T> t;
	int n;
	
	BIT(int _n){
		n=_n;
		t.assign(n+1,0);
	}
	void upd(int i, T v){ // add v to ith element
		for(int j=i+1;j<=n;j+=j&-j)t[j]+=v;
	}
	T get(int i){ // get sum of range [0,i0)
		T ans=0;
		for(int j=i;j;j-=j&-j)ans+=t[j];
		return ans;
	}
	T get(int l, int r){ // get sum of range [l,r]
		return get(r+1)-get(l);
	}
};
