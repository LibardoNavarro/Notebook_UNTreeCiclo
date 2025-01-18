mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// check if two n*n matrix a*b=c within complexity (iteration*n^2)
// probability of error 2^(-iteration)
// O(iter*n^2)
int Freivalds(matrix &a, matrix &b, matrix &c) {
	int n = a.r, iteration = 20;
	matrix zero(n, 1), r(n, 1);
	while (iteration--) {
		for(int i = 0; i < n; i++) r.m[i][0] = rnd() % 2;
		matrix ans = (a * (b * r)) - (c * r);
		if(ans.m != zero.m) return 0;
	}
	return 1;
}