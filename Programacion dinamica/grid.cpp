#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w; cin >> h >> w;
    vector<string> grid(h);

    for (string &s: grid) cin >> s;

    vector<vector<int>> dp(h+1, vector<int>(w+1, 0));

    dp[0][0] = 1;

    for (int i = 0; i<h; i++){
        for (int  j = 0; j<w; j++){
            char z = grid[i][j];
            if (grid[i][j] == '.' && (i != 0 || j !=0)){
                if (i == 0){
                    dp[i][j] = dp[i][j-1] % 1000000007;
                }
                else if( j == 0){
                    dp[i][j] = dp[i-1][j] % 1000000007;
                }
                else{
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
                }
            }
        }
    }

    // for (int i = 0; i<h; i++){
    //     for (int j = 0; j<w; j++){
    //         cout <<dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[h-1][w-1] % 1000000007;
}