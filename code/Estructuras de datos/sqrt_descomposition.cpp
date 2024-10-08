typedef long long T;
struct Sqrt { // O(n/b+b)
	int b; // check b
	vector<T> nums,blocks;
	void build(vector<T>& arr, int n){
		b=(int)ceil(sqrt(n));nums=arr;
		blocks.assign(b, 0);
		for(int i=0;i<n;++i){
			blocks[i/b]+=nums[i];
		}
	}

	void set(int x, int v){
		blocks[x/b]-=nums[x];
		nums[x]=v;
		blocks[x/b]+=nums[x];
	}

	T get(int r){
		T res=0;
		for(int i=0;i<r/b;++i){res+=blocks[i];}
		for(int i=(r/b)*b;i<r;++i){res+=nums[i];}
		return res;
	}

	T get(int l, int r){return get(r+1)-get(l);}
};
