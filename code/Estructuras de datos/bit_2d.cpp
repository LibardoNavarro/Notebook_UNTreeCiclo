typedef long long T;

// 0-indexed 
// build O(n*m) - upd, get O(log(n)*log(m))
struct BIT2D{ 
	int n,m; 
	vector<vector<T>> bit;
	BIT2D(int _n, int _m){
		n=_n;m=_m;
		bit.assign(n+1, vector<T>(m+1,0));
	}
	T get(int x, int y){
		if(x<0 || y<0)return 0;
		T v=0;
		for(int i=x+1;i;i-=i&-i)
			for(int j=y+1;j;j-=j&-j)v+=bit[i][j];
		return v;
	}
	T get(int x, int y, int x2, int y2){
		return get(x2,y2)-get(x-1,y2)-get(x2,y-1)+get(x-1,y-1);
	}
	void upd(int x, int y, T dt){
		if(x<0 || y<0)return;
		for(int i=x+1;i<=n;i+=i&-i)
			for(int j=y+1;j<=m;j+=j&-j)bit[i][j]+=dt;
	}
};