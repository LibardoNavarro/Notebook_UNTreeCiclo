struct matrix {
	int r, c; vector<vl> m;
	matrix(int r, int c, const vector<vl> &m) : r(r), c(c), m(m){}

	matrix operator * (const matrix &b){
		matrix ans(this->r, b.c, vector<vl>(this->r, vl(b.c, 0)));

		for (int i = 0; i<this->r; i++) {
			for (int k = 0; k<b.r; k++){
				if (m[i][k] == 0) continue;
				for (int j = 0; j<b.c; j++){
					ans.m[i][j] += mod(m[i][k], MOD) * mod(b.m[k][j], MOD);
					ans.m[i][j] = mod(ans.m[i][j], MOD);
				}
			}
		}
		return ans;
	}
};

matrix pow(matrix &b, ll p){
	matrix ans(b.r, b.c, vector<vl>(b.r, vl(b.c, 0)));
	for (int i = 0; i<b.r; i++) ans.m[i][i] = 1;
	while (p){
		if (p&1){
			ans = ans*b;
		}
		b = b*b;
		p >>= 1;
	}
	return ans;
}