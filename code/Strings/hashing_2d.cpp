// Revisar primero los comentarios en hashing!!!
// 1-indexed

const ii BX(3731, 3731), BY(2999, 2999);
const int MOD[2] = { 998244353, 1001265673 }; 

int add(int a, int b, int m){return a+b>=m?a+b-m:a+b;}
int sbt(int a, int b, int m){return a-b<0?a-b+m:a-b;}
int mul(int a, int b, int m){return ll(a)*b%m;} 
ll operator ! (const ii a) { return (ll(a.first) << 32) | a.second; }
ii operator + (const ii& a, const ii& b){return {add(a.first, b.first, MOD[0]), add(a.second, b.second, MOD[1])};}
ii operator - (const ii& a, const ii& b){return {sbt(a.first, b.first, MOD[0]), sbt(a.second, b.second, MOD[1])};}
ii operator * (const ii& a, const ii& b){return {mul(a.first, b.first, MOD[0]), mul(a.second, b.second, MOD[1])};}

const int maxn = 1e6+5;
ii PX[maxn], PY[maxn];
void prepare(){ // remember!!!
	PX[0] = PY[0] = ii{1,1}; 
	rep(i,1,maxn) {
		PX[i] = PX[i-1] * BX; 
		PY[i] = PY[i-1] * BY; 
	}
} 

template <class type> 
struct Hashing2D { // 1-indexed
	vector<vector<ii>> hs;
	int n, m;
	Hashing2D(vector<type>& s) {
		n = sz(s), m = sz(s[0]);
		hs.assign(n + 1, vector<ii>(m + 1, {0,0}));
		rep(i, 0, n) rep(j, 0, m) 
			hs[i + 1][j + 1] = {s[i][j], s[i][j]};
		rep(i, 0, n+1) rep(j, 0, m) 
			hs[i][j + 1] = hs[i][j + 1] + hs[i][j] * BY;
		rep(i, 0, n) rep(j, 0, m+1) 
			hs[i + 1][j] = hs[i + 1][j] + hs[i][j] * BX;
	}
	ii get(int x1, int y1, int x2, int y2) { 
		assert(1 <= x1 && x1 <= x2 && x2 <= n);
		assert(1 <= y1 && y1 <= y2 && y2 <= m);
		x1--;y1--;
		int dx = x2 - x1, dy = y2 - y1;
		return (hs[x2][y2] - hs[x2][y1] * PY[dy]) - 
			(hs[x1][y2] - hs[x1][y1] * PY[dy])  * PX[dx];
	}
};