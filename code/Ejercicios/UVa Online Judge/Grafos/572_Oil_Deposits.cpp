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

int m, n;

void floodfill(vector<string> &grid, int r, int c){
    grid[r][c] = '.';
    for (int i = 0; i<8; i++){
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 || nr >= m || nc<0 || nc>=n) continue;
        if (grid[nr][nc] == '@') floodfill(grid, nr, nc);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true){
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        vector<string> grid(m);
        for (int i = 0; i<m; i++){
            cin >> grid[i];
        }
        int ans = 0;
        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (grid[i][j] == '@') {floodfill(grid, i, j); ans++;}
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}