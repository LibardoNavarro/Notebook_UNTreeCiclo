// dp[pos][count of d][limit]
ll dp[20][20][2];
int k,d;

// count numbers <= c with k occurrences of d
ll dfs(string& c, int x=0, int y=0, bool z=0){
	if(dp[x][y][z]!=-1)return dp[x][y][z];
	dp[x][y][z]=(y==k);
	if(x==(int)c.size()){
		return dp[x][y][z];
	}
	int limit=9;
	if(!z){
		limit=c[x]-'0';
	}
	dp[x][y][z]=0;
	for(int i=0;i<=limit;++i){
		if(z)dp[x][y][z]+=dfs(c, x+1, y+(i==d), z);
		else dp[x][y][z]+=dfs(c, x+1, y+(i==d), i<limit);
	}
	return dp[x][y][z];
}

// count(0,m) - count(0,n-1) = count(n,m)
ll query(ll n, ll m){
	string s1=to_string(m);
	string s2=to_string(n-1ll);
	memset(dp, -1, sizeof(dp));
	ll ans=dfs(s1);
	if(n<=0ll)return ans;
	memset(dp, -1, sizeof(dp));
	return ans-dfs(s2);
}
