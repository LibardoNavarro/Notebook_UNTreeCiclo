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

    int l, t; cin >> l >> t;
    vector<vl> costos(t, vl(3));

    for (int i = 0; i<t; i++){
        for (int j = 0; j<3; j++){
            cin >> costos[i][j];
        }
    }

    vector<vl> dp(t+1, vl(l+1, INFL));
    dp[0][0] = 0;

    for (int i = 1; i<=t; i++){
        for (int j = 0; j<=l; j++){
            dp[i][j] = dp[i-1][j];
            for (int k = 1; k <= min(j, 3); k++) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-k] + costos[i-1][k - 1]);
            }
        }
    }

        // for (int i = 1; i<=l; i++){
        //     for (int j = 1; j<=t; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

    cout << dp[t][l] << "\n";
    
    return 0;
}