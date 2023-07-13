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

struct dsu{
    vi p, size;
    int num_sets;
    int maxSize = 0;

    dsu(int n){
        p.assign(n, 0);
        size.assign(n, 1);
        num_sets = n;
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int find_set(int i) {
        return (p[i] == i) ? i : (p[i] = find_set(p[i]));
    }

    bool is_same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }

    void unionSet(int i, int j){
        if (!is_same_set(i, j)){
            int a = find_set(i), b = find_set(j);
            if (size[a] < size[b])
                swap(a, b);
            p[b] = a;
            size[a] += size[b];
            maxSize = max(size[a], maxSize);
            num_sets--;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);

    int n; cin >> n;
    vector<vi> grid(n, vi(n));
    dsu farm(n*n);

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++) cin >> grid[i][j];
    }

    vector<pair<int, ii>> aristas;

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            for (int d = 0; d<4; d++){
                int r = i + dirx[d]; int c = j + diry[d];
                if ((r < 0 || r >= n || c< 0 || c >= n) || grid[i][j] < grid[r][c]) continue;
                aristas.push_back({grid[i][j] - grid[r][c], {i*n + j, r*n + c}});
            }
        }
    }

    sort(aristas.begin(), aristas.end());

    for (pair<int, ii> arista : aristas){
        farm.unionSet(arista.second.first, arista.second.second);
        if (farm.maxSize >= (n*n)/2) {
            cout << arista.first << "\n";
            break;
        }
    }
    
    return 0;
}