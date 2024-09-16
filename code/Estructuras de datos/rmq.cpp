typedef long long T;
T oper(T a, T b); // max, min, gcd ...
struct RMQ { // O(n)/O(1)
	vector<vector<T>> table;
	void build(vector<T>& v){
		int n=v.size();
		table.assign(20, vector<T>(n));
		for(int i=0;i<n;++i)table[0][i]=v[i];
		for(int j=1;(1<<j)<=n;++j)
			for(int i=0;i+(1<<(j-1))<n;++i)
				table[j][i]=oper(table[j-1][i],table[j-1][i+(1<<(j-1))]);
	}
	T get(int l, int r){
		int j=31-__builtin_clz(r-l+1);
		return oper(table[j][l], table[j][r-(1<<j)+1]);
	}
};
