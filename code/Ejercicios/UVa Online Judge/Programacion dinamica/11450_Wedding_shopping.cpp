#include <bits/stdc++.h>
using namespace std;

#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;
int dirx[4] = {0, -1, 1, 0};
int diry[4] = {-1, 0, 0, 1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    while(n--){
        int m, c; cin >> m >> c;
        vector<vl> precios(c);
        for (int i = 0; i<c; i++){
            int k; cin >> k;
            precios[i].resize(k);
            for (int j = 0; j<k; j++){
                cin >> precios[i][j];
            }
        }
        for (int i = 0; i<c; i++) sort(precios[i].begin(), precios[i].end());

        vector<vl> dp(c+1, vl(m+1, 0));

        for (int i = 1; i<=c; i++){
            for (int j = 1; j<=m; j++){
                dp[i][j] = dp[i-1][j];
                for (int k = 0; k<sz(precios[i-1]); k++){
                    if (precios[i-1][k] > j) break;
                    dp[i][j] = max(dp[i][j], dp[i-1][j-precios[i-1][k]] + precios[i-1][k]);
                }
            }
        }
        ll min = 0;
        for (int i = 0; i<c; i++) min+=precios[i][0];
        if (dp[c][m]>=min) cout << dp[c][m] << "\n";
        else cout << "no solution" << "\n";

    }
    
    return 0;
}