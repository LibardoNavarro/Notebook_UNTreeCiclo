const int maxn = 1e5+5,alpha = 26;
int aut[maxn][alpha];

// O(n*alpha)
void build(string& s){ 
	aut[0][conv(s[0])]=1;
	int n=sz(s);
	for(int i=1,p=0;i<n+1;++i){
		for(int j=0;j<alpha;++j)aut[i][j]=aut[p][j];
		if(i<n){
			aut[i][conv(s[i])]=i+1;
			p=aut[p][conv(s[i])];
		}
	}
}
