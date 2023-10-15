#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const double EPS  = 1e-9;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

void khan(vector<vi> &adj, vi &grado, vi &ans, int n){
    queue<int> q;
    for (int i = 1; i<=n; i++){
        if (!grado[i]) q.push(i);
    }
    while (!q.empty()){
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (int v : adj[u]){
            grado[v]--;
            if (!grado[v]) q.push(v);
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
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        grado[b]++;
    }
    vi ans;
    khan(adj, grado, ans, n);

    if (sz(ans) == n){
        for (int i : ans) cout << i << " ";
    }
    else cout << "IMPOSSIBLE";

    return 0;
}