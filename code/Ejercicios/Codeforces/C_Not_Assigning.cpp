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

void dfs(vector<vi> &adj, vi &vis, int s, map<ii, int> &m, int a){
    vis[s] = 1;
    for (int vecino : adj[s]){
        if (!vis[vecino]) {m[{s, vecino}] = m[{vecino, s}] = (a%2==0?2:3); dfs(adj, vis, vecino, m, a+1);}
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        vi grados(n+1, 0);
        bool b = true;
        vector<vi> adj(n+1);
        vector<ii> ans(n-1);
        for (int i = 0; i<n-1; i++){
            int u, v; cin >> u >> v;
            grados[u]++; grados[v]++;
            if (grados[u] >= 3 || grados[v] >= 3) b = false;
            ans[i] = {u, v}; adj[u].push_back(v); adj[v].push_back(u);
        }
        if (!b) cout << -1 << ln;
        else{
            vi vis(n+1, 0);
            map<ii, int> m;
            for (int i = 1; i<=n; i++){
                if (grados[i] == 1) {dfs(adj, vis, i, m, 0); break;}
            }
            for (ii p : ans) cout << m[p] << " ";
            cout << ln;
        }
    }
    
    return 0;
}