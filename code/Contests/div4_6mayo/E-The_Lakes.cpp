#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

int dfs(vector<vi>& grid, vector<vector<bool>>& visited, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();
    vii directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int volume = grid[i][j];
    visited[i][j] = true;

    for (auto dir : directions) {
        int ni = i + dir.first;
        int nj = j + dir.second;
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && grid[ni][nj] > 0) {
            volume += dfs(grid, visited, ni, nj);
        }
    }

    return volume;
}

int encontrarMayorVolumen(vector<vi>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int mayorVolumen = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] > 0) {
                int volumen = dfs(grid, visited, i, j);
                mayorVolumen = max(mayorVolumen, volumen);
            }
        }
    }

    return mayorVolumen;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vi> grid(n, vi(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int mayorVolumen = encontrarMayorVolumen(grid);
        cout << mayorVolumen << endl;
    }

    return 0;
}
