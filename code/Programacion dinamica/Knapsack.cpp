#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ll n, w; cin >> n >> w;
    vl pesos(n+1);
    vl valores(n+1);

    for (ll i = 1; i<=n; i++){
        cin >> pesos[i] >> valores[i];
    }

    vector<vl> dp(n+1, vl(w+1, 0));

    for (ll i = 1; i<=n; i++){
        for (ll j = 1; j<=w; j++){
            if (j < pesos[i]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-pesos[i]] + valores[i]);
            }
            
        }
    }

    cout << dp[n][w];
    return 0;
}