// lo mismo que sparse table, pero para st opers
// O(n*log(n)) build
// O(1) get
typedef int T;
T null = 0;
T op(T a, T b){return a^b;}
struct DST {
	vector<vector<T>> pre, suf;
	int k, n;
	DST(vector<T>& a) {
		n = sz(a);
		k = log2(n) + 2;
		pre.assign(k + 1, vector<T>(n));
		suf.assign(k + 1, vector<T>(n));
		for(int j = 0; (1 << j) <= n; ++j) {
			int mask = (1 << j) - 1;
			T nw = null; 	
			for(int i = 0; i < n; ++i) {
				nw = op(nw, a[i]);
				pre[j][i] = nw;
				if((i & mask) == mask) nw = null; 
			}
			nw = null; 
			for(int i = n - 1; i >= 0; --i) {
				nw = op(a[i], nw);
				suf[j][i] = nw;
				if((i & mask) == 0) nw = null;
			}
		}
	}
	T get(int l, int r) {
		if(l == r) return pre[0][l];
		int i = 31 - __builtin_clz(l ^ r);
		return op(suf[i][l], pre[i][r]);
	}
};