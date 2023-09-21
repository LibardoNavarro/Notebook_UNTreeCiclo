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
char dir[4] = {'U', 'L', 'R', 'D'};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

int bfs(vector<string> &grid, map<ii, pair<ii,char>> &parent, int n, int m, ii s, ii t){
    queue<ii> q; q.push(s);
    vector<vi> dist(n, vi(m, -1));
    dist[s.first][s.second] = 0;
    while (!q.empty()){
        ii casilla = q.front(); q.pop();
        int r = casilla.first, c = casilla.second;
        if (casilla == t) return dist[r][c];
        for (int i = 0; i<4; i++){
            if (r+diry[i] < 0 || r+diry[i] >= n || c+dirx[i] < 0 || c+dirx[i] >= m) continue;
            if (grid[r+diry[i]][c+dirx[i]] == '#' || grid[r+diry[i]][c+dirx[i]] == '+') continue;
            dist[r+diry[i]][c+dirx[i]] = dist[r][c] + 1;
            parent[{r+diry[i], c+dirx[i]}] = {{r, c}, dir[i]};
            grid[r+diry[i]][c+dirx[i]] = '+';
            q.push({r+diry[i], c+dirx[i]});
        }
    }
    return 0;
}

void path(map<ii, pair<ii, char>> &parent, ii inicio, ii final){
    if (inicio == final) return;
    path(parent, inicio, parent[final].first);
    cout << parent[final].second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i<n; i++) cin >> grid[i];
    ii s, t;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if (grid[i][j] == 'A') s = {i, j};
            else if (grid[i][j] == 'B') t = {i, j};
        }
    }
    map<ii, pair<ii, char>> parent;
    int ans = bfs(grid, parent, n, m, s, t);
    if (ans){
        cout << "YES\n";
        cout << ans << ln;
        path(parent, s, t);
    }
    else cout << "NO\n";
    return 0;
}