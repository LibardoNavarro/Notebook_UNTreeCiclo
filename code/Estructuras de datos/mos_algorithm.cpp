// O((n+q)*s), s=n^(1/2)
// O(q*(s+(n/s)^2) => O(q*(n^(2/3))), s=(2*(n^2))^(1/3) - s=n^(2/3)
int s,n;
struct upd{int i,old,cur;};
struct query {int l,r,t,idx;};
bool cmp(query& a, query& b){
	int x=a.l/s;
	if(a.l/s!=b.l/s)return a.l/s<b.l/s;
	if(a.r/s!=b.r/s)return (x&1?a.r<b.r:a.r>b.r);
	return a.t<b.t;
}

vector<int> ans;
vector<query> qu;
vector<upd> up;

int act();
void add(int i);
void remove(int i);
void update(int i,int v,int l,int r){
	if(l<=i && i<=r); // add, remove
}

void solve(){
	s=(int)ceil(sqrt(n));
	sort(all(qu), cmp);
	int l=0,r=-1,t=0;
	for(int i=0;i<sz(qu);++i){
		while(t<qu[i].t)update(up[t].i,up[t].cur,l,r),++t;
		while(t>qu[i].t)--t,update(up[t].i,up[t].old,l,r);
		while(r<qu[i].r)add(++r);
		while(l>qu[i].l)add(--l);
		while(r>qu[i].r)remove(r--);
		while(l<qu[i].l)remove(l++);
		ans[qu[i].idx]=act();
	}
}

// tree
int st[maxn],ft[maxn],ver[maxn*2];
bool vis[maxn];

void ask(int v){
	vis[v]=!vis[v];
	if(vis[v])add(v);
	else remove(v);
}

// query[i] = {st[a]+1, st[b], i} + lca
	