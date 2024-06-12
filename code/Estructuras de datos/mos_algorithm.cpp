// O((n+q)*sqrt(n))
int sqrtn,n;
struct query {int l, r, idx;};
bool cmp (query a, query b) {
	int x = a.l/sqrtn;
	if (x != b.l/sqrtn) return x < b.l/sqrtn;
	return (x&1 ? a.r < b.r : a.r > b.r);
}

vector<int> ans;
vector<query> q;

int act();
void add(int i);
void remove(int i);

void solve(){
	sqrtn=(int)ceil(sqrt(n));
	sort(all(q), cmp);
	int l=0,r=-1;
	for(int i=0;i<sz(q);++i){
		while(r<q[i].r)add(++r);
		while(l>q[i].l)add(--l);
		while(r>q[i].r)remove(r--);
		while(l<q[i].l)remove(l++);
		ans[q[i].idx]=act();
	}
}
