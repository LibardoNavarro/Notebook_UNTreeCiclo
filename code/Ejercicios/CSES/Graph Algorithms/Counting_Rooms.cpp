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

void bfs(vector<string> &grid, int r, int c, int n, int m){
    grid[r][c] = '+';
    queue<ii> q; q.push({r, c});

    while (!q.empty()){
        ii nodo = q.front(); q.pop();
        r = nodo.first, c = nodo.second;

        for (int i = 0; i<4; i++){
            if (r+diry[i] < 0 || r+diry[i] >= n || c+dirx[i] < 0 || c+dirx[i] >= m) continue;
            if (grid[r+diry[i]][c+dirx[i]] != '.') continue;
            q.push({r+diry[i], c+dirx[i]});
            grid[r+diry[i]][c+dirx[i]] = '+';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i<n; i++) cin >> grid[i];

    ll ans = 0;

    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if (grid[i][j] == '.'){
                bfs(grid, i, j, n, m);
                ans++;
            }
        }
    }

    cout << ans << ln;
    
    return 0;
}