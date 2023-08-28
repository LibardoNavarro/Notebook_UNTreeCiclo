int main() {
    int inf =9999999;
    
    int n,x;cin>>n>>x;
    // n: numero de monedas x: la cantidad buscada
    vi coins(n); // valor de cada moneda
    for (int i=0;i<n;i++) cin>>coins[i];
    vector<vi> dp(n+1,vi(x+1,0));

    for (int i=0;i<=x;i++) dp[0][i]=inf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if (j<coins[i-1]) dp[i][j] = dp[i-1][j]; 
            else dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);  
        }
    }

    int res = dp[n][x];
    cout<<(res==inf?-1:res)<<ln;
}