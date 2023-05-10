#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF 1000000000;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

vector<string> grid; int n, m;
string ans1;

int floodfill(int r, int c, char c1, char c2){
    if (r < 0 || r >= n || c< 0 || c >= m) return "";
    if (grid[r][c] != c1) return "";
    string ans = string::s(1, c1);
    grid[r][c] = c2;
    for (int d = 0; d < 8; d++){
        ans += (floodfill(r + dr[d], c + dc[d], abc[(int) (abc.find(c1)) + 1], c2) + floodfill(r + dr[d], c + dc[d], abc[(int) (abc.find(c1)) - 1], c2));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    grid = vector<string>(n);

    for (int i = 0; i<n; i++){
        cin >> grid[i];
    }
    string max = "";

    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            string z =  floodfill(i, j, grid[i][j], '.');
            if (z.) {
                max = z;
            }
        }
    }
    cout << max << " " << ans1;
}