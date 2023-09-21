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
int dir[4] = {'U', 'L', 'R', 'D'};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';
ll ans = 0;
void dfs(vector<vi> grid, int r, int c, int R, int C, char d){
    if (r < 0 || r >= R || c< 0 || c >= C) {ans++; return;}
    grid[r][c] = 1;
    int detener = 0;
    if (d == 'U') {
        if(!(r-1 < 0 || r-1 >= R || c< 0 || c >= C) && grid[r-1][c] == -1) {
            dfs(grid, r-1, c, R, C, 'U');
            detener++;
        }
        if(!(r < 0 || r >= R || c+1< 0 || c+1 >= C) && grid[r][c+1] == -1) {
            dfs(grid, r, c+1, R, C, 'R');
            detener++;
        }
    }
    else if (d == 'D'){
        if(!(r+1 < 0 || r+1 >= R || c< 0 || c >= C) && grid[r+1][c] == -1){
            dfs(grid, r+1, c, R, C, 'D');
            detener++;
        }
        if(!(r < 0 || r >= R || c-1< 0 || c-1 >= C) && grid[r][c-1] == -1){
            dfs(grid, r, c-1, R, C, 'L');
            detener++;
        }
    }
    else if (d == 'R'){
        if(!(r < 0 || r >= R || c+1< 0 || c+1 >= C) && grid[r][c+1] == -1){
            dfs(grid, r, c+1, R, C, 'R');
            detener++;
        }
        if(!(r+1 < 0 || r+1 >= R || c< 0 || c >= C) && grid[r+1][c] == -1){
            dfs(grid, r+1, c, R, C, 'D');
            detener++;
        }
    }
    else{
        if(!(r < 0 || r >= R || c-1< 0 || c-1 >= C) && grid[r][c-1] == -1){
            dfs(grid, r, c-1, R, C, 'L');
            detener++;
        }
        if(!(r-1 < 0 || r-1 >= R || c< 0 || c >= C) && grid[r-1][c] == -1){
            dfs(grid, r-1, c, R, C, 'U');
            detener++;
        }
    }
    if (!detener) ans++;

    // for (int i = 0; i<4; i++){
    //     if (r+diry[i] < 0 || r+diry[i] >=R || c+dirx[i] < 0 || c+dirx[i] >=C) ans++;
    //     if (grid[r+diry[i]][c+dirx[i]] == -1) dfs(grid, r+diry[i], c+dirx[i], R, C, d);
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;
    
    while (t--){
        ans = 0;
        int R, C; cin >> R >> C;
        vector<vi> grid(R, vi(C, -1));
        dfs(grid, R-1, 0, R, C, 'U');
        cout << ans << ln;
    }

    return 0;
}