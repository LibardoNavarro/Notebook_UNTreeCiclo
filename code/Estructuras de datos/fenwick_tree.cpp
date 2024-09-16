typedef long long T;
struct FwTree{ 
	int n;
	vector<T> bit;
	FwTree(int n): n(n),bit(n+1){}
	T get(int r){
		T sum=0;
		for(++r;r;r-=r&-r)sum+=bit[r];
		return sum;
	}
	T get(int l, int r){return get(r)-(l==0?0:get(l-1));}
	void upd(int r, T v){
		for(++r;r<=n;r+=r&-r)bit[r]+=v;
	}
};

struct FwTree2d{ 
	int n, m;
	vector<vector<T>> bit;
	FwTree2d(){}
	FwTree2d(int n, int m):n(n),m(m),bit(n+1, vector<T>(m+1,0)){}
	T get(int x, int y){
		T v=0;
		for(int i=x+1;i;i-=i&-i)
		for(int j=y+1;j;j-=j&-j)v+=bit[i][j];
		return v;
	}
	T get(int x, int y, int x2, int y2){return get(x2,y2)-get(x-1,y2)-get(x2,y-1)+get(x-1,y-1);}
	void upd(int x, int y, T dt){
		for(int i=x+1;i<=n;i+=i&-i)
		for(int j=y+1;j<=m;j+=j&-j)bit[i][j]+=dt;
	}
};
