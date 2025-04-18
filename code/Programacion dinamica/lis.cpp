// O(n*log(n))
int lis(vi& a){
	int n=sz(a),last=0;
	vi dp(n+1,INT_MAX),cnt(n,0);
	dp[0]=INT_MIN;
	for(int i=0;i<n;++i){
		int j=lower_bound(all(dp), a[i])-dp.begin(); // upper_bound
		if(dp[j-1]<a[i] && a[i]<dp[j]){ // dp[j-1]<=a[i]
			dp[j]=a[i];
			last=max(last,j);
		}
		cnt[i]=j;
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		if(dp[i]<INT_MAX)ans=i;
	}
	vi LIS(ans);
	int act=ans;
	for(int i=n-1;i>=0;--i){
		if(cnt[i]==act){
			LIS[act-1]=a[i];
			act--;
		}
	}
	return ans;
}