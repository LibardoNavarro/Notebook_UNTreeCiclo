// O((n+q)*s), s=n^(1/2)
int s,n;
struct query {int l,r,idx;};
bool cmp(query& a, query& b){
	int x=a.l/s;
	if(a.l/s!=b.l/s)return a.l/s<b.l/s;
	return (x&1?a.r<b.r:a.r>b.r);
}

vector<query> queries;
vector<ll> ans;
vector<ll> a;

ll act();
void add(int i); // add a[i]
void remove(int i)// remove a[i]

void solve(){
	s=ceil(sqrt(n));
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
