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
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vi> matrix(n+1, vi(m+1));
    int unos = 0;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) unos++;
        }
    }
    vector<vi> matrix2(n+1, vi(m+1));
    int ans = 0;
    vii anss;
    for (int i = 1; i<n; i++){
        for (int j = 1; j<m; j++){
            if (matrix[i][j] == 1 && matrix[i+1][j] == 1 && matrix[i][j+1] == 1 && matrix[i+1][j+1] == 1){
                ans++;
                anss.push_back({i, j});
                matrix2[i][j] = 1; matrix2[i+1][j] = 1; matrix2[i][j+1] = 1; matrix2[i+1][j+1] = 1;
            }
        }
    }
    if (matrix2 == matrix){
        cout << ans << "\n";
        for (int i = 0; i<sz(anss); i++) cout << anss[i].first << " " << anss[i].second << "\n";
    }
    else cout << -1 << "\n";
    
    return 0;
}