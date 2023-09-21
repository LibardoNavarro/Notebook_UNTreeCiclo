#include <bits/stdc++.h>
using namespace std;

#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
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

const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        vector<string> grid(10);
        ll ans = 0;
        for (int i = 0; i<10; i++){
            for (int j = 0; j<10; j++){
                cin >> grid[i][j];
                if (grid[i][j] == 'X'){
                    if (i == 0 || i == 9 || j == 0 || j == 9) ans += 1;
                    else if (i == 1 || i == 8 || j == 1 || j == 8) ans+= 2;
                    else if (i == 2 || i == 7 || j == 2 || j == 7) ans+= 3;
                    else if (i == 3 || i == 6 || j == 3 || j == 6) ans+= 4;
                    else ans += 5;
                }

            }
        }
        cout << ans << ln;
    }
    
    return 0;
}