// c[k] = sumatoria (i&j = k, += a[i]*b[j]) AND convolution
// c[k] = sumatoria (i|j = k, += a[i]*b[j]) OR convolution
// c[k] = sumatoria (i^j = k, += a[i]*b[j]) XOR convolution
// c[k] = sumatoria (gcd(i,j) = k, += a[i]*b[j]) GCD convolution 
// c[k] = sumatoria (lcm(i,j) = k, += a[i]*b[j]) LCM convolution 
// todas las funciones tienen operaciones con modulo
// si es indexando en 1 entonces se pone un cero al principio y listo

template<int MOD> struct mint {
	static const int mod = MOD;
	int v; 
	explicit operator int() const { return v; } 
	mint():v(0) {}
	mint(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
	void build(ll _v) { v=int(_v%MOD), v+=(v<0)*MOD; }
	mint& operator+=(mint o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(mint o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(mint o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	friend mint pow(mint a, ll p) { assert(p >= 0);
		return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
	friend mint inv(mint a) { assert(a.v != 0); return pow(a,MOD-2); }
	friend mint operator+(mint a, mint b) { return a += b; }
	friend mint operator-(mint a, mint b) { return a -= b; }
	friend mint operator*(mint a, mint b) { return a *= b; }
};
using mi = mint<998244353>;

template<typename T>
void SubsetZetaTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i] += v[i ^ j];
	}
}

template<typename T>
void SubsetMobiusTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i] -= v[i ^ j];
	}
}

template<typename T>
void SupersetZetaTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i ^ j] += v[i];
	}
}

template<typename T>
void SupersetMobiusTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i ^ j] -= v[i];
	}
}

vector<int> PrimeEnumerate(int n) {
	vector<int> P; vector<bool> B(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		if (B[i]) P.push_back(i);
		for (int j : P) { if (i * j > n) break; B[i * j] = 0; if (i % j == 0) break; }
	}
	return P;
}

template<typename T>
void DivisorZetaTransform(vector<T>& v) {
	const int n = sz(v) - 1;
	for (int p : PrimeEnumerate(n)) {
		for (int i = 1; i * p <= n; i++)
			v[i * p] += v[i];
	}
}

template<typename T>
void DivisorMobiusTransform(vector<T>& v) {
	const int n = sz(v) - 1;
	for (int p : PrimeEnumerate(n)) {
		for (int i = n / p; i; i--)
			v[i * p] -= v[i];
	}
}

template<typename T>
void MultipleZetaTransform(vector<T>& v) {
	const int n = sz(v) - 1;
	for (int p : PrimeEnumerate(n)) {
		for (int i = n / p; i; i--)
			v[i] += v[i * p];
	}
}

template<typename T>
void MultipleMobiusTransform(vector<T>& v) {
	const int n = sz(v) - 1;
	for (int p : PrimeEnumerate(n)) {
		for (int i = 1; i * p <= n; i++)
			v[i] -= v[i * p];
	}
}

template<typename T>
vector<T> AndConvolution(vector<T> A, vector<T> B) {
	SupersetZetaTransform(A);
	SupersetZetaTransform(B);
	for (int i = 0; i < sz(A); i++) A[i] *= B[i];
	SupersetMobiusTransform(A);
	return A;
}

template<typename T>
vector<T> OrConvolution(vector<T> A, vector<T> B) {
	SubsetZetaTransform(A);
	SubsetZetaTransform(B);
	for (int i = 0; i < sz(A); i++) A[i] *= B[i];
	SubsetMobiusTransform(A);
	return A;
}

template<typename T>
vector<T> GCDConvolution(vector<T> A, vector<T> B) {
	MultipleZetaTransform(A);
	MultipleZetaTransform(B);
	for (int i = 0; i < sz(A); i++) A[i] *= B[i];
	MultipleMobiusTransform(A);
	return A;
}

template<typename T>
vector<T> LCMConvolution(vector<T> A, vector<T> B) {
	DivisorZetaTransform(A);
	DivisorZetaTransform(B);
	for (int i = 0; i < sz(A); i++) A[i] *= B[i];
	DivisorMobiusTransform(A);
	return A;
}

template<typename T> 
vector<T> XORConvolution(vector<T> A, vector<T> B) { 
	const int n = sz(A); 
	auto FWT = [&](vector<T>& v) { 
		for (int len = 1; len < n; len <<= 1) { 
			for (int i = 0; i < n; i += (len << 1)) { 
				for (int j = 0; j < len; j++) { 
					T u(v[i + j]);
					T w(v[i + j + len]); 
					v[i + j] = u + w; v[i + j + len] = u - w; 
				} 
			} 
		} 
	}; 
	FWT(A); FWT(B); 
	for (int i = 0; i < n; i++) A[i] *= B[i]; 
	FWT(A); 
	T inv_n(inv(T(n))); 
	for (int i = 0; i < n; i++) A[i] *= inv_n; 
	return A; 
}

void main2(){
	int n;
	cin>>n;
	vector<mi> a(1<<n),b(1<<n);
	for(int x,i=0;i<sz(a);++i){cin>>x;a[i].build(x);}
	for(int x,i=0;i<sz(b);++i){cin>>x;b[i].build(x);}
	vector<mi> ans=XORConvolution(a,b);
	for(int i=0;i<sz(ans);++i)cout<<ans[i].v<<" ";
}