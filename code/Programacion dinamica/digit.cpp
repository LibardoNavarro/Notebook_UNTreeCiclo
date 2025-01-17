ll dp[20][20][2];
int k,d;

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

ll query(ll l, ll r){
	string s1=to_string(l-1ll);
	string s2=to_string(r);
	ll ans=dfs(s2);
	memset(dp, -1, sizeof(dp));
	return ans-dfs(s1);
}
