// 1000234999, 1000567999, 1000111997, 1000777121, 1001265673, 1001864327, 999727999, 1070777777
typedef pair<int, int> ii;
const int mod[2] = { 1001864327, 1001265673 }; 
// each char must be positive or compare hashes with same length
const ii base(257, 367); // base => alpha => has to be prime
const int maxn = 1e6;

int add(int a, int b, int m){return a+b>=m?a+b-m:a+b;}
int sbt(int a, int b, int m){return a-b<0?a-b+m:a-b;}
int mul(int a, int b, int m){return ll(a)*b%m;} 
ll operator ! (const ii a){return (ll(a.first)<<32)|a.second;}
ii operator + (const ii& a, const ii& b){return {add(a.first, b.first, mod[0]), add(a.second, b.second, mod[1])};}
ii operator - (const ii& a, const ii& b){return {sbt(a.first, b.first, mod[0]), sbt(a.second, b.second, mod[1])};}
ii operator * (const ii& a, const ii& b){return {mul(a.first, b.first, mod[0]), mul(a.second, b.second, mod[1])};}

ii p[maxn+1];
void prepare(){
	p[0]={1,1};
	for(int i=1;i<=maxn;i++)p[i]=p[i-1]*base;
}

template <class type> 
struct hashing{
	vector<ii> h;
	hashing(type& t){
		h.resize(sz(t)+1);
		h[0]={0,0};
		for(int i=1;i<sz(h);++i)
			h[i]=h[i-1]*base + ii{t[i-1], t[i-1]};
	}

	ii get(int l, int r){
		return h[r+1]-h[l]*p[r-l+1];
	}
};

// combine two hashes
ii combine(ii a, ii b, int lenb){
	return a*p[lenb]+b;
}

// O(n) constructor
// O(1) get
// 1. prepare() in the main
// 2. hashing<string> hs("hello");
// 3. hs.get(l,r);
