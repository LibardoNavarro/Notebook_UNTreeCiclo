// O((n+q)*sq), sq=n^(1/2)
// 1. fill queries[]
// 2. solve(n);
// 3. print ans[]
int sq;
struct query {int l,r,idx;};
bool cmp(query& a, query& b){
	int x=a.l/sq;
	if(a.l/sq!=b.l/sq)return a.l/sq<b.l/sq;
	return (x&1?a.r<b.r:a.r>b.r);
}

vector<query> queries;
vector<ll> ans;

ll act();
void add(int i); // add a[i]
void remove(int i); // remove a[i]

void solve(int n){
	sq=ceil(sqrt(n));
	sort(all(queries), cmp);
	ans.assign(sz(queries),0);
	int l=0,r=-1;
	for(auto [li,ri,i]:queries){
		while(r<ri)add(++r);
		while(l>li)add(--l);
		while(r>ri)remove(r--);
		while(l<li)remove(l++);
		ans[i]=act();
	}
}