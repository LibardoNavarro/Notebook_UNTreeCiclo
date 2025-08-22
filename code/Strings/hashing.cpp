// O(n) build - O(1) get
// 1. prepare() in the main
// 2. hashing<string> hs("hello");
// 3. hs.get(l,r);

// Chars are in [1, BASE)
// BASE is prime or random(lim, MOD-lim)
// If chars are in [0, BASE) then compare the hashes for length
// 1000234999, 1000567999, 1000111997, 1000777121, 1001265673, 1001864327, 999727999, 1070777777

const ii BASE(257, 367);
const int MOD[2] = { 1001864327, 1001265673 }; 

int add(int a, int b, int m){return a+b>=m?a+b-m:a+b;}
int sbt(int a, int b, int m){return a-b<0?a-b+m:a-b;}
int mul(int a, int b, int m){return ll(a)*b%m;} 
ll operator ! (const ii a) { return (ll(a.first) << 32) | a.second; }
ii operator + (const ii& a, const ii& b){return {add(a.first, b.first, MOD[0]), add(a.second, b.second, MOD[1])};}
ii operator - (const ii& a, const ii& b){return {sbt(a.first, b.first, MOD[0]), sbt(a.second, b.second, MOD[1])};}
ii operator * (const ii& a, const ii& b){return {mul(a.first, b.first, MOD[0]), mul(a.second, b.second, MOD[1])};}

const int maxn = 1e6+5;
ii pot[maxn];
void prepare(){ // remember!!!
	pot[0] = ii{1,1}; 
	rep(i,1,maxn) pot[i] = pot[i-1] * BASE; 
} 

template <class type> 
struct Hashing{
	vector<ii> h;
	Hashing(type& t){
		h.assign(sz(t)+1, ii{0,0});
		rep(i,1,sz(h)) h[i] = h[i-1] * BASE + ii{t[i-1], t[i-1]};
	}

	ii get(int l, int r){
		return h[r+1] - h[l] * pot[r-l+1];
	}
};

ii combine(ii a, ii b, int lenb){
	return a * pot[lenb] + b;
}