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

struct dsu{
    vi p, size;
    int num_sets;
    int maxSize;

    dsu(int n){
        p.assign(n, 0);
        size.assign(n, 1);
        num_sets = n;
        maxSize = 1;
        for (int i = 0; i<n; i++) p[i] = i;
    }

    int find_set(int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

    bool is_same_set(int i, int j) {return find_set(i) == find_set(j);}

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

    while (true){
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<pair<ii, ll>> edges;
        ll wmax = -INFL;
        for (int i = 0; i<m; i++){
            int u, v; ll w; cin >> u >> v >> w;
            wmax = max(w, wmax);
            edges.push_back({{u-1, v-1}, w});
        }
        dsu graph(n);
        for (auto edge : edges){
            if (edge.second == wmax) {graph.unionSet(edge.first.first, edge.first.second);}
        }

        cout << graph.maxSize << "\n";
    }
    
    return 0;
}