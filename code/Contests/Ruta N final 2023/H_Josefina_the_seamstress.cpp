#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

const char ln = '\n';
int mod = 1e9+7;

int main() {

    int w = 0;
    while(cin >> w, w!=0){
        int n=2;
        vi pesos;
        vi valor;
        for (int i = 0; i < n; i++) {
            int p,v;cin >> p;
            pesos.push_back(p);
            valor.push_back(1);
        }

        ll dp[n+1][w+1] ={0};

        for (int i =0;i<=n;i++) dp[i][0]=0;
        for (int i =0;i<=w;i++) dp[0][i]=0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                ll op1 = dp[i-1][j];
                ll op2;
                if (j<pesos[i-1]){
                    op2=0;
                }
                else{
                    op2=pesos[i-1]+dp[i][j-pesos[i-1]];
                }
                dp[i][j] = max(op1,op2);
            }
        }

        ll res = dp[n][w];
        cout<< w - res << "\n";
        w = 0;
    }
}