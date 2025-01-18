// Given alphabet [0, k) constructs a cyclic string
// of length k^n that contains every length n string as substr. 
vi deBruijnSeq(int k, int n, int lim){
	if (k == 1) return {0};
	vi seq, aux(n + 1); 
	int cont = 0;
	function<void(int,int)> gen = [&](int t, int p) {
		if (t > n){
			if (n % p == 0) for(int i = 1; i < p + 1; i++){
				if (cont >= lim) return;
				seq.pb(aux[i]);
				cont++;
			} 
		} else {
			aux[t] = aux[t - p]; 
			gen(t + 1, p);
			while (++aux[t] < k){
				if (cont >= lim) return;
				gen(t + 1, t);
			}
		}
	};
	gen(1, 1); 
	return seq;
}