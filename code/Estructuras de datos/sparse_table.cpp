// O(n*log(n)) build
// O(1) get
typedef long long T;
T op(T a, T b); // max, min, gcd ...
struct Table{ 
	vector<vector<T>> st;
	Table(vector<T>& v){
		st.clear();
		int n=v.size();
		st.push_back(v);
		for(int j=1;(1<<j)<=n;++j){
			st.push_back(vector<T>(n));
			for(int i=0;i+(1<<(j-1))<n;++i){
				st[j][i]=op(st[j-1][i],st[j-1][i+(1<<(j-1))]);
			}
		}
	}
	T get(int l, int r){
		int j=31-__builtin_clz(r-l+1);
		return op(st[j][l], st[j][r-(1<<j)+1]);
	}
};