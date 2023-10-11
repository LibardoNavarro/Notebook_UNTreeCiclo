#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const double EPS  = 1e-9;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

int mod (int a, int m) {return ((a%m)+m)%m;}

bool bfs(vector<string> &grid, string s, int r, int c){
    vector<vi> valido(r, vi(c, 1));
    vector<vi> vis(r, vi(c, 0));
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            for (int k = 0; k<c; k++){
                if (s[(j+k)%c] == '1' && grid[i][k] == '1') {valido[i][j] = 0; break;}
            }
        }
    }
    queue<ii> q;
    for (int i = 0; i<c; i++){
        if (valido[0][i]) {
            q.push({0, i});
            vis[0][i] = 1;
        }
    }

    while (!q.empty()){
        ii nodo = q.front(); q.pop();
        for (int i = 0; i<4; i++){
            int nx = nodo.first + diry[i];
            if (nx < 0 || nx>=r) continue;
            int ny = mod(nodo.second + dirx[i], c);
            if (valido[nx][ny] && !vis[nx][ny]){
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }

    for (int i = 0; i<c; i++) {if (vis[r-1][i]) return true;}
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int r, c; cin >> r >> c;
    string s; cin >> s;
    vector<string> grid(r);
    for (int i = 0; i<r; i++) cin >> grid[i];

    if (bfs(grid, s, r, c)){
        cout << "Y\n";
    }
    else{
        reverse(all(s));
        if (bfs(grid, s, r, c)){
            cout << "Y\n";
        }
        else cout << "N\n";
    }

    return 0;
}