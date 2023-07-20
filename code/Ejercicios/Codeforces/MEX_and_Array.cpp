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

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vi v(n);
        for (int i = 0; i<n; i++) cin >> v[i];

        int ans = 0;
        for (int i = 0; i<n; i++){
            ans += (i+1) * (n-i);
            if (v[i] == 0) ans += (i+1) * (n-i);
        }
        cout << ans << "\n";
    }

    return 0;
}