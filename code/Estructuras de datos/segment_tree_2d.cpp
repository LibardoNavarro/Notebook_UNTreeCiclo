// O(n^2*log(n^2)) build
// O(log(n)^2) get, set
const int N=1000+1;
typedef int T;
T st[2*N][2*N];
struct SegTree{
	int n,m,neutro=0;
	T op(T a, T b){return a+b;}
	SegTree(int n, int m): n(n), m(m){ 
		for(int i=0;i<2*n;++i)for(int j=0;j<2*m;++j)st[i][j]=neutro; 
	}
	SegTree(vector<vector<T>>& a): n(sz(a)), m(n ? sz(a[0]) : 0){ build(a); } 
	void build(vector<vector<T>>& a){
		for(int i=0;i<n;++i)for(int j=0;j<m;++j)st[i+n][j+m]=a[i][j];
		for(int i=0;i<n;++i)for(int j=m-1;j>=1;--j)st[i+n][j]=op(st[i+n][j<<1], st[i+n][j<<1|1]);
		for(int i=n-1;i>=1;--i)for(int j=0;j<2*m;++j)st[i][j]=op(st[i<<1][j], st[i<<1|1][j]);
	}
	void set(int x, int y, T v){
		st[x+n][y+m]=v;
		for(int j=y+m;j>1;j>>=1)st[x+n][j>>1]=op(st[x+n][j], st[x+n][j^1]);
		for(int i=x+n;i>1;i>>=1)for(int j=y+m;j;j>>=1)st[i>>1][j]=op(st[i][j], st[i^1][j]);
	}
	T get(int x0, int y0, int x1, int y1){
		T r=neutro;
		for(int i0=x0+n,i1=x1+n+1;i0<i1;i0>>=1,i1>>=1){
			int t[4],q=0;
			if(i0&1)t[q++]=i0++;
			if(i1&1)t[q++]=--i1;
			for(int k=0;k<q;++k)for(int j0=y0+m,j1=y1+m+1;j0<j1;j0>>=1,j1>>=1){
				if(j0&1)r=op(r,st[t[k]][j0++]);
				if(j1&1)r=op(r,st[t[k]][--j1]);
			}
		}
		return r;
	}
};