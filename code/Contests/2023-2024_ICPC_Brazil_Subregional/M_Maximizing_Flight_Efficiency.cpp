#include <bits/stdc++.h>
using namespace std;

#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
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

const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

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

int dijkstra(vector<vii> &adj, int s, int t, int n){
    vi dist(n+1, INT_MAX); dist[s] = 0;
    priority_queue<ii, vii, greater<ii> > pq; pq.push(ii(0, s));
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;

        for (int j = 0; j < (int)adj[u].size(); j++){
            ii v = adj[u][j];
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    return dist[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n; cin >> n;

    vector<vi> c(n, vi(n));
    vector<pair<int, ii>> adj;
    set<ii> estan;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++) {
            cin >> c[i][j];
            if (!c[i][j]) c[i][j] = INF;
            else {
                if (!estan.count({i, j}) && !estan.count({j, i})){
                    estan.insert({i, j});
                    adj.push_back({c[i][j], {i, j}});
                }
            }
        }
    }

    vector<vi> adjM = c;

    for (int k = 0; k<n; k++)
        for (int i = 0; i<n; i++)
            for (int j = 0; j<n; j++)
                adjM[i][j] = min(adjM[i][j], adjM[i][k] + adjM[k][j]);

    bool b = true;

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (c[i][j] != INF && adjM[i][j] != c[i][j]) {b = false; break;}
        }
    }

    if (!b) cout << -1 << ln;
    else{
        sort(all(adj));
        dsu graph(n);
        vector<vii> adj2(n);
        int ans = 0;
        for (auto edge : adj){
            int u = edge.second.first, v = edge.second.second, w = edge.first;
            if (!graph.is_same_set(u, v)) {
                graph.unionSet(u, v);
                adj2[u].push_back({v, w});
                adj2[v].push_back({u, w});
            }
            else {
                if (dijkstra(adj2, u, v, n) <= w) ans++;
            }
        }
        cout << ans << ln;
    }

    return 0;
}