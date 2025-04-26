// O(n*m*log(n)*log(m)) build 
// O(1) get
typedef int T;
const int maxn = 1000, logn = 10;
T st[logn][maxn][logn][maxn];
int lg2[maxn+1];
T op(T a, T b){return max(a,b);}; // min, max, gcd...

void build(int n, int m, vector<vector<T>>& a){
	for(int i=2;i<=max(n,m);++i)lg2[i]=lg2[i/2]+1;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) 
			st[0][i][0][j]=a[i][j];
		for(int k2=1;k2<logn;++k2) 
			for(int j=0;j+(1<<(k2-1))<m;++j) 
				st[0][i][k2][j]=op(st[0][i][k2-1][j], st[0][i][k2-1][j+(1<<(k2-1))]);
	}
	for(int k1=1;k1<logn;++k1) 
		for(int i=0;i<n;++i) 
			for(int k2=0;k2<logn;++k2) 
				for(int j=0;j<m;++j) 
					st[k1][i][k2][j]=op(st[k1-1][i][k2][j], st[k1-1][i+(1<<(k1-1))][k2][j]);
}
T get(int x1, int y1, int x2, int y2){
	x2++;y2++;
	int a=lg2[x2-x1];
	int b=lg2[y2-y1];
	return op(
		op(st[a][x1][b][y1], 
			st[a][x2-(1<<a)][b][y1]),
		op(st[a][x1][b][y2-(1<<b)], 
			st[a][x2-(1<<a)][b][y2-(1<<b)])
	);
}
