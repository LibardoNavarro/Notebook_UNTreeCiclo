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

    while (t--) {
        vector<string> grid(8);
        for (int i = 0; i<8; i++){
            cin >> grid[i];
        }
        string ans = "";
        bool b = false;
        for (int i = 0; i<8; i++){
            for (int j = 0; j<8; j++){
                if (grid[j][i] != '.'){
                    ans += grid[j][i];
                }
                else if (ans != "" && grid[j][i] == '.'){
                    b = true;
                    break;
                }
            }
            if (b) break;
        }
        cout << ans << "\n";
    }

    return 0;
}