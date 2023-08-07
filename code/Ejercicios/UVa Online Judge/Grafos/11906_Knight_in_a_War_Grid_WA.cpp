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
int dirxx[4] = {1, -1, 1, -1};
int diryy[4] = {1, 1, -1, -1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int R, C, m, n;

void dfs(vector<vi> &grid, int r, int c, vector<vi> &ans){
    if (grid[r][c] == 1) return;
    grid[r][c] = 1;
    for (int i = 0; i<4; i++){
        int nr = r + diryy[i]*m;
        int nc = c + dirxx[i]*n;
        if (!(nr >= R || nr< 0 || nc >= C || nc< 0)){
            if (grid[nr][nc] != -1){
                ans[nr][nc]++;
                dfs(grid, nr, nc, ans);
            }
        }
        nr = r + diryy[i]*n;
        nc = c + dirxx[i]*m;
        if (!(nr >= R || nr< 0 || nc >= C || nc< 0)){
            if (grid[nr][nc] != -1){
                ans[nr][nc]++;
                dfs(grid, nr, nc, ans);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    for (int z = 1; z<=t; z++){
        cin >> R >> C >> m >> n;
        vector<vi> grid(R, vi(C, 0));
        int w; cin >> w;
        for (int i = 0; i<w; i++){
            int a, b; cin >> a >> b; a; b;
            grid[a][b] = -1;
        }
        vector<vi> ans(R, vi(C, 0));
        dfs(grid, 0, 0, ans);
        int pares = 0, impares = 0;
        for (int i = 0; i<R; i++){
            for (int j = 0; j<C; j++){
                if (grid[i][j] != 1) continue;
                if (ans[i][j] % 2 == 0) pares++;
                else impares++;
            }
        }
        cout << "Case " << z << ": " << pares << " " << impares << "\n";
    }
    
    return 0;
}