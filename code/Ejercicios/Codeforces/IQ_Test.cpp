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

    vector<string> grid(4);
    for (int i = 0; i<4; i++){
        string s; cin >> s;
        grid[i] = s;
    }
    bool b = false;
    for (int i = 0; i<4; i++){
        for (int j = 0; j<4; j++){
            if (i+1 >= 4 || j+1 >=4) continue;
            string car = "";
            car += grid[i][j];
            car += grid[i+1][j];
            car += grid[i][j+1];
            car += grid[i+1][j+1];
            int p = 0;
            int n = 0;
            for (int z = 0; z<4; z++){
                if (car[z] == '.') p++;
                else n++;
            }
            if (p>=3 || n>=3) {b = true; break;}
        }
        if (b) break;
    }
    if (b) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    
    return 0;
}