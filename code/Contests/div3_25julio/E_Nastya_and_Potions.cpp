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

vl solve(vector<vl> &adj, vl &grado, vl &c, int n){
    queue<int> q;
    vl costos(n+1, 0);
    for (int i = 1; i<=n; i++){
        if (!grado[i]) {q.push(i); costos[i] += c[i];}
    }
    int nodo;
    while(!q.empty()){
        nodo = q.front(); q.pop();
        costos[nodo] = min(costos[nodo], c[nodo]);
        for (int v : adj[nodo]){
            grado[v]--;
            costos[v] += costos[nodo];
            if (grado[v] == 0) q.push(v);
        }
    }
    return costos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--){
        int n, k; cin >> n >> k;

        vl c(n+1);
        for (int i = 1; i<=n; i++) cin >> c[i];

        for (int i = 0; i<k; i++){int a; cin >> a; c[a] = 0;}
        vector<vl> adj(n+1);
        vl grado(n+1, 0);
        for (int i = 1; i<=n; i++){
            int m; cin >> m;
            for (int j = 0; j<m; j++){
                int v; cin >> v;
                adj[v].push_back(i);
                grado[i]++;
            }
        }

        vl ans = solve(adj, grado, c, n);

        for (int i = 1; i<=n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    
    return 0;
}