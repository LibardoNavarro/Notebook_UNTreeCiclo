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
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vi> graph(n);

    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    stack<int> p;
    for (int i = 0; i<n; i++){
        int a; cin >> a; a--;
        p.push(a);
    }

    dsu farm(n);
    vector<string> ans(n);
    vi act(n);
    for (int i = 0; i<n; i++){
        int nodo = p.top(); p.pop();
        act[nodo] = 1;
        if (i == 0) {
            ans[i] = "YES";
        }
        else{
            for (int j = 0; j<sz(graph[nodo]); j++){
                if (act[graph[nodo][j]]) farm.unionSet(nodo, graph[nodo][j]);
            }
            if (farm.num_sets == n-i) ans[i] = "YES";
            else ans[i] = "NO";
        }
    }

    for (int i = 0; i<n; i++){
        cout << ans[n-1-i] << "\n";
    }
    
    return 0;
}