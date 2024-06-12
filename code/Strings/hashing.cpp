const int MOD[2] = { 1001864327, 1001265673 }; // 1000234999, 1000567999, 1000111997, 1000777121, 1001265673, 1001864327, 999727999, 1070777777
const ii BASE(257, 367), ZERO(0, 0), ONE(1, 1);
const int MAXN = 1e6;

inline int add(int a, int b, int mod){return a+b >= mod ? a+b-mod : a+b;}
inline int sbt(int a, int b, int mod){return a-b < 0 ? a-b+mod : a-b;}
inline int mul(int a, int b, int mod){return ll(a) * b % mod;} 
inline ll operator ! (const ii a){return (ll(a.F) << 32) | a.S;}
inline ii operator + (const ii& a, const ii& b){return {add(a.F, b.F, MOD[0]), add(a.S, b.S, MOD[1])};}
inline ii operator - (const ii& a, const ii& b){return {sbt(a.F, b.F, MOD[0]), sbt(a.S, b.S, MOD[1])};}
inline ii operator * (const ii& a, const ii& b){return {mul(a.F, b.F, MOD[0]), mul(a.S, b.S, MOD[1])};}

ii p[MAXN+1];
void prepare(){
	p[0]=ONE;
	for(int i=1;i<=MAXN;i++)p[i]=p[i-1]*BASE;
}

// Acordate del prepare()!!
template <class type> 
struct hashing {
	vector<ii> h;
	hashing(type &t) {
		h.resize((int)t.size()+1);
		h[0]=ZERO;
		for (int i=1;i<(int)h.size();++i)
			h[i]=h[i-1]*BASE + ii{t[i-1], t[i-1]};
	}

	ii query(int l, int r){
		return h[r+1]-h[l]*p[r-l+1];
	}
};