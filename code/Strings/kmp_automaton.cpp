const int maxn = 1e5+5, alpha = 26;
int to[maxn][alpha];

// O(n*alpha)
void build(string& s){
	to[0][conv(s[0])]=1;
	int n=sz(s);
	for(int i=1,p=0;i<n+1;++i){
		for(int j=0;j<alpha;++j)to[i][j]=to[p][j];
		if(i<n){
			to[i][conv(s[i])]=i+1;
			p=to[p][conv(s[i])];
		}
	}
}
