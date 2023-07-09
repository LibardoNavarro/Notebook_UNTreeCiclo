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
    int maxSize;

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

    int n, m; cin >> n >> m;

    dsu graph(n);

    for (int i = 0; i<m; i++){
        int u, v; cin >> u >> v; u--; v--;
        graph.unionSet(u, v);
    }

    int k; cin >> k;
    set<ii> edges;

    for (int i = 0; i<k; i++){
        int x, y; cin >> x >> y; x--; y--;
        int a = graph.find_set(x);
        int b = graph.find_set(y);
        if (a<b){
            edges.insert({a, b});
        }
        else{
            edges.insert({b, a});
        }
    }

    int z; cin >> z;
    for (int i = 0; i<z; i++){
        int p, q; cin >> p >> q; p--; q--;
        int a = graph.find_set(p);
        int b = graph.find_set(q);
        int c = 0;
        if ( a < b) c = edges.count({a, b});
        else c = edges.count({b, a});

        if (!c){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << "\n";
        }
    }
    
}