struct segtree{
	int n; vl v; ll nulo = 0;

	ll op(ll a, ll b) {return a + b;}

	segtree(int n) : n(n) {v = vl(2*n, nulo);}

	segtree(vl &a) : n(sz(a)), v(2*n){
		for(int i = 0; i<n; i++) v[n + i] = a[i];
		for (int i = n-1; i>=1; --i) v[i] = op(v[i<<1], v[i<<1|1]);
	}

	void upd(int k, ll nv){
		for (v[k += n] = nv; k > 1; k >>= 1) v[k>>1] = op(v[k], v[k^1]);
	}

	ll get(int l, int r){
		ll vl = nulo, vr = nulo;
		for (l += n, r += n+1; l < r; l >>= 1, r >>= 1){
			if (l&1) vl = op(vl, v[l++]);
			if (r&1) vr = op(v[--r], vr);
		}
		return op(vl, vr);
	}
};