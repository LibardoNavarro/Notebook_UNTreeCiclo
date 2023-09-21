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

ii bfs1(vector<string> &grid, int n, int m, vector<vi> &dist){
    queue<ii> q;
    ii hola;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if (grid[i][j] == 'M') {q.push({i, j}); dist[i][j] = 0;}
            else if (grid[i][j] == 'A') hola = {i, j};
        }
    }
    while (!q.empty()){
        ii casilla = q.front(); q.pop();
        int r = casilla.first, c = casilla.second;
        for (int i = 0; i<4; i++){
            if (r+diry[i] < 0 || r+diry[i] >= n || c+dirx[i] < 0 || c+dirx[i] >= m) continue;
            if (dist[r+diry[i]][c+dirx[i]] != -1 || grid[r+diry[i]][c+dirx[i]] == '#') continue;
            dist[r+diry[i]][c+dirx[i]] = dist[r][c] + 1;
            q.push({r+diry[i], c+dirx[i]});
        }
    }
    return hola;
}

pair<pair<bool, int>, ii> bfs2(vector<string> &grid, int n, int m, int r1, int c1, vector<vi> &dist1, vector<vi> &dist2, map<ii, pair<ii, char>> &parent){
    queue<ii> q; q.push({r1, c1}); dist2[r1][c1] = 0;
    while (!q.empty()){
        ii casilla = q.front(); q.pop();
        int r = casilla.first, c = casilla.second;
        if (r == 0 || r == n-1 || c == 0 || c == m-1) {return {{true, dist2[r][c]}, {r, c}};}
        for (int i = 0; i<4; i++){
            if (r+diry[i] < 0 || r+diry[i] >= n || c+dirx[i] < 0 || c+dirx[i] >= m) continue;
            if (dist2[r+diry[i]][c+dirx[i]] != -1 || grid[r+diry[i]][c+dirx[i]] == '#' || grid[r+diry[i]][c+dirx[i]] == 'M') continue;
            if (dist1[r+diry[i]][c+dirx[i]] == -1){
                q.push({r+diry[i], c+dirx[i]});
                dist2[r+diry[i]][c+dirx[i]] = dist2[r][c] + 1;
                parent[{r+diry[i], c+dirx[i]}] = {{r, c}, dir[i]};
            }
            else if (dist2[r][c] + 1 < dist1[r+diry[i]][c+dirx[i]]){
                q.push({r+diry[i], c+dirx[i]});
                dist2[r+diry[i]][c+dirx[i]] = dist2[r][c] + 1;
                parent[{r+diry[i], c+dirx[i]}] = {{r, c}, dir[i]};
            }
        }
    }
    return {{false, 0}, {0, 0}};
}

void path(map<ii, pair<ii, char>> &parent, ii inicio, ii final){
    if (inicio == final) return;
    ii nuevo = parent[final].first;
    path(parent, inicio, nuevo);
    cout << parent[final].second << "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i<n; i++) cin >> grid[i];
    vector<vi> dist1(n, vi(m, -1));
    ii hola = bfs1(grid, n, m, dist1);
    vector<vi> dist2(n, vi(m, -1));
    map<ii, pair<ii, char>> parent;
    auto ans = bfs2(grid, n, m, hola.first, hola.second, dist1, dist2, parent);
    if (ans.first.first){
        cout << "YES\n";
        cout << ans.first.second << ln;
        path(parent, hola, ans.second);
        // for (auto pa : parent) cout << pa.first.first << " " << pa.first.second << " padre: " << pa.second.first.first << " " << pa.second.first.second << ln;
    }
    else{
        cout << "NO\n";
    }
    
    return 0;
}