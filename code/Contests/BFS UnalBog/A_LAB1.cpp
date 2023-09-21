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

ll bfs(vector<string> &grid, int n, int m, int r, int c, int x, int y){
    ll ans = 1;
    deque<pair<ii, ii>> q; q.push_front({{r-1, c-1}, {0, 0}});
    while (!q.empty()){
        auto celda = q.front(); q.pop_front();
        int r = celda.first.first, c = celda.first.second;
        grid[r][c] = '+';
        for (int i = 0; i<4; i++){
            if (r+diry[i] < 0 || r+diry[i] >= n || c+dirx[i] < 0 || c+dirx[i] >= m) continue;
            if (grid[r+diry[i]][c+dirx[i]] == '*' || grid[r+diry[i]][c+dirx[i]] == '+') continue;
            if (dirx[i] == 1) {
                if (celda.second.second+1 > y) continue;
                q.push_back({{r+diry[i], c+dirx[i]}, {celda.second.first, celda.second.second+1}});
                ans++;
            }
            else if (dirx[i] == -1) {
                if (celda.second.first+1 > x) continue;
                q.push_back({{r+diry[i], c+dirx[i]}, {celda.second.first+1, celda.second.second}});
                ans++;
            }
            else {q.push_front({{r+diry[i], c+dirx[i]}, {celda.second.first, celda.second.second}}); ans++;}
            grid[r+diry[i]][c+dirx[i]] = '+';
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m, r, c, x, y; cin >> n >> m >> r >> c >> x >> y;
    vector<string> grid(n);
    for (int i = 0; i<n; i++) cin >> grid[i];
    cout << bfs(grid, n, m, r, c, x, y) << ln;
    // for (int i = 0; i<n; i++) cout << grid[i] << ln;
    
    return 0;
}