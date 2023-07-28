#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, p; cin >> k >> p;

    vector<int> arroz(p);
    for (int i = 0; i < p; i++) {
        cin >> arroz[i];
    }

    vector<vector<int>> dp(p+1, vector<int>(5 * 10e4 +1, 0));

    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= 5 * 10e4; j++) {
            if (j >= arroz[i-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-arroz[i-1]] + arroz[i-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for (int i = 0; i <= p; i++) {
    //     for (int j = 0; j <= 17; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        cout << dp[p][lower_bound(dp[p].begin(), dp[p].end(), n) - dp[p].begin()] - n << "\n";
    } 
        
    
}