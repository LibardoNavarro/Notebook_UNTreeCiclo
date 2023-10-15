const int nMax = 1005;
int dp[nMax][nMax];
// Longest Common Subsequence O(n*m) (devuelve el tamano)
int lcs(const string &s, const string &t){
  int n=len(s),m=len(t);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      if(s[i-1]==t[j-1])dp[i][j]=max(dp[i][j], dp[i-1][j-1] + 1);
    }
  }
  return dp[n][m];
}

// Devuelve la subsecuencia O(s*t)
string lcs_str(const string &s, const string &t){
  int n=len(s),m=len(t);
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  int i=n,j=m;
  string res="";
  while(i>0 && j>0) {
      if(s[i - 1]==t[j-1]){
        res=s[i-1]+res;i--;j--;
      }else if(dp[i-1][j]>dp[i][j-1])i--;
      else j--;
  }
  return res;
}