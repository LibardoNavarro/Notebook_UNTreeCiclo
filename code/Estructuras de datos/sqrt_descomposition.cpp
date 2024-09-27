// O(n/sqrt(n)+sqrt(n)) query
struct Sqrt {
	int block_size;
	vi nums;vl blocks;
	Sqrt(vi &arr){
		block_size=(int)ceil(sqrt(sz(arr)));
		blocks.assign(block_size, 0);
		nums=arr;
		for(int i=0;i<sz(nums);++i){
			blocks[i/block_size]+=nums[i];
		}
	}
	void update(int x, int v){
		blocks[x/block_size]-=nums[x];
		nums[x]=v;
		blocks[x/block_size]+=nums[x];
	}
	ll query(int r){
		ll res=0;
		for(int i=0;i<r/block_size;++i){res+=blocks[i];}
		for(int i=(r/block_size)*block_size;i<r;++i){res+=nums[i];}
		return res;
	}
	ll query(int l, int r){return query(r)-query(l-1);}
};
