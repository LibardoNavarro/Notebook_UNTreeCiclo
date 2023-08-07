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

    int n; cin >> n;

    while (n--){
        int s, p; cin >> s >> p;
        vii puntos(p);
        for (int i = 0; i<p; i++){
            int x, y; cin >> x >> y;
            puntos[i] = {x, y};
        }
        vector<pair<double, ii>> adj;
        for (int i = 0; i<p-1; i++){
            for (int j = i+1; j<p; j++){
                double d = sqrtl((puntos[i].first - puntos[j].first) * (puntos[i].first - puntos[j].first) + (puntos[i].second - puntos[j].second) * (puntos[i].second - puntos[j].second));
                adj.push_back({d, {i, j}});
            }
        }
        sort(adj.begin(), adj.end());
        dsu mst(p);
        for (auto a : adj){
            double w = a.first; 
            int i = a.second.first, j = a.second.second;
            if (!mst.is_same_set(i, j)){
                mst.unionSet(i, j);
                if (mst.num_sets == s) {cout << fixed << setprecision(2) << w << "\n"; break;}
            }
        }
    }
    
    return 0;
}