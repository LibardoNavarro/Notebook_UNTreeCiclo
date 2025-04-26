// O(q*(s+(n/s)^2) => O(q*(n^(2/3))), s=(2*(n^2))^(1/3) - s=n^(2/3)
// 1. fill queries[] and upds[]
// dont confuse index in queries with updates, they are different
// the struct upd saves the old value and the new value
// 2. solve(n);
// 3. print ans[]
int sq;
struct upd{int i,old,cur;};
struct query {int l,r,t,idx;};
bool cmp(query& a, query& b){
	int x=a.l/sq;
	if(a.l/sq!=b.l/sq)return a.l/sq<b.l/sq;
	if(a.r/sq!=b.r/sq)return (x&1?a.r<b.r:a.r>b.r);
	return a.t<b.t;
}

vector<query> queries;
vector<upd> upds;
vector<ll> ans;

ll act();
void add(int i); // add a[i]
void remove(int i); // remove a[i]
void update(int i, int v, int l, int r){
	// check if the update is with an active element
	if(l<=i && i<=r){
		remove(i);
		// a[i]=v;
		// ...
		add(i);
	}
	// a[i]=v;
	// ...
}

void solve(int n){
	sq=ceil(pow(n,2.0/3.0));
	sort(all(queries), cmp);
    ans.resize(sz(queries));
	int l=0,r=-1,t=0;
	for(auto [li,ri,ti,i]:queries){
		while(t<ti)update(upds[t].i,upds[t].cur,l,r),++t;
		while(t>ti)--t,update(upds[t].i,upds[t].old,l,r);
		while(r<ri)add(++r);
		while(l>li)add(--l);
		while(r>ri)remove(r--);
		while(l<li)remove(l++);
		ans[i]=act();
	}
}
