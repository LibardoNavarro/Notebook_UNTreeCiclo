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

int floodfill(int r, int c, char c1){
    if (grid[r][c] != c1 || (ans1.find(c1) != string::npos)) return 0;
    int ans = 1;
    ans1 += c1;
    string ans2 = ans1;
    for (int d = 0; d < 8; d++){

        int f = r + dr[d]; int g = c + dc[d];
        ans1 = ans2;
        if (f < 0 || f >= n || g< 0 || g >= m) continue;
        ans += floodfill(f, g, c1 +1);
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
    int max = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            ans1 = "";
            int z =  floodfill(i, j, grid[i][j]);
            if (z > max) {
                max = z;
            }
        }
    }
    cout << max;
}