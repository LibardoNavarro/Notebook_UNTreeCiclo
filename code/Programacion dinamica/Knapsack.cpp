int main() {
    int n,w;cin>>n>>w;
    // w es la capacidad de la mochila
    // n es la cantidad de elementos
    vi pesos;
    vi valor;
    for (int i = 0; i < n; i++) {
        int p,v;cin >> p>>v;
        pesos.push_back(p);
        valor.push_back(v);
    }

    ll dp[n+1][w+1] ={0};

    for (int i =0;i<=n;i++) dp[i][0]=0;
    for (int i =0;i<=w;i++) dp[0][i]=0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            ll op1 = dp[i-1][j];
            ll op2;
            if (j<pesos[i-1])op2=0;
            else op2=valor[i-1]+dp[i-1][j-pesos[i-1]];
            dp[i][j] = max(op1,op2);
        }
    }

    ll res = dp[n][w];
    cout<<res;
}