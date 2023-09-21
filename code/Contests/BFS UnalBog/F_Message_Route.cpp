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

int bfs(vector<vi> &adj, vi &parent, int s, int t, int n){
    vi dist(n+1, -1);
    queue<int> q; q.push(s);
    dist[s] = 0;
    while (!q.empty()){
        int nodo = q.front(); q.pop();
        for (int vecino : adj[nodo]){
            if (dist[vecino] == -1) {
                q.push(vecino);
                dist[vecino] = dist[nodo] + 1;
                parent[vecino] = nodo;
            }
        }
    }
    return dist[t];
}

void path(vi &parent, int s, int t){
    if (s == t) {cout << s << " "; return;}
    path(parent, s, parent[t]);
    cout << t << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;
    vector<vi> adj(n+1);
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi parent(n+1);
    int ans = bfs(adj, parent, 1, n, n);

    if (ans != -1){
        cout << ans+1 << ln;
        path(parent, 1, n);
    }
    else cout << "IMPOSSIBLE\n";

    return 0;
}