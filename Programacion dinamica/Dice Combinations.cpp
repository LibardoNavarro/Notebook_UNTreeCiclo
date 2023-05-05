#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vl dp(n+1);
    dp[0] = 1;

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=6; j++){
            if ( i >= j){
                dp[i] = (dp[i] + dp[i-j]) % 1000000007;
            }
        }
    }

    cout << dp[n];
}