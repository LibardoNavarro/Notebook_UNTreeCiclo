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

void bfs(vector<vi> &adj, int s, int n){
    vi dist(n+1, -1);
    queue<int> q; q.push(s);
    dist[s] = 0;
    while (!q.empty()){
        int nodo = q.front(); q.pop();
        for (int vecino : adj[nodo]){
            if (dist[vecino] == -1) {
                q.push(vecino);
                dist[vecino] = dist[nodo] + 1;
                cout << nodo << " " << vecino << ln;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;

    vector<vi> adj(n+1);
    vi grado(n+1, 0);
    int maxgrado = -INF;
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        grado[a]++;
        grado[b]++;
        maxgrado = max(max(grado[a], grado[b]), maxgrado);
    }
    for (int i = 1; i<=n; i++){
        if (grado[i] == maxgrado) {bfs(adj, i, n); break;}
    }

    return 0;
}