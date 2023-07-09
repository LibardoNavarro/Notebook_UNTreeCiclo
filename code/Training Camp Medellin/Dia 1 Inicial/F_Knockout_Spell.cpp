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
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;

    vector<vi> grid(n);
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            int a; cin >> a;
            grid[i].push_back(a);
        }
    }
    ll ans = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (i+k-1 >= n || j+k-1 >=n) continue;
            vi nums;
            int a = grid[i][j];
            nums.push_back(grid[i][j]);
            nums.push_back(grid[i+k-1][j]);
            nums.push_back(grid[i][j+k-1]);
            nums.push_back(grid[i+k-1][j+k-1]);
            bool b = true;
            for (int z = 1; z<=3; z++){
                if (nums[z] != a) b = false;
            }
            if (b) ans++;
        }
    }
    cout << ans << "\n";
    
}