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

pair<bool, int> bellman_ford(vector<vll> &adj, vi &p, vl &d, vector<bool> &vis, int s, int n){
    d.assign(n+1, INFL);
    p.assign(n+1, -1);
    d[s] = 0LL;
    vis[s] = true;
    for (int i = 0; i<n-1; i++){
        bool cambio = false;
        for (int u = 1; u<=n; u++){
            if (d[u] == INFL)continue;
            for (auto [v, w] : adj[u]){
                if (d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    vis[v] = true;
                    p[v] = u;
                    cambio = true;
                }
            }
        }
        if (!cambio) {return {true, 0};}
    }

    for (int u = 1; u<=n; u++){
        if (d[u] == INFL)continue;
        for (auto [v, w] : adj[u]){
            if (d[v] > d[u] + w) return {false, u};
        }
    }
    return {true, 0};
}

void print(vi &p, int s, int t){
    if (s == t) {cout << s << " "; return;}
    if (s == -1) {cout << t << " "; return;}
    print(p, p[s], t);
    cout << s << " ";
}

void solve(vector<vll> &adj, vi &p, int n){
    vl d(n+1, INFL);
    vector<bool> vis(n+1, false);
    for (int i = 1; i<=n; i++){
        if (!vis[i]) {
            auto a = bellman_ford(adj, p, d, vis, i, n);
            if (!a.first){
                cout << "YES\n";
                vi v(n+1, -1);
                int temp = a.second;
                for (int z = 0; z<n; z++) {
                    a.second = p[a.second];
                    if (a.second == temp) break;
                }
                print(p, p[a.second], a.second);
                cout << a.second << ln;
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;

    vector<vll> adj(n+1);
    int hola = 0;
    for (int i = 0; i<m; i++){
        int a, b; ll c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        if (a == b && c<0) hola = a;
    }
    if (hola) {cout << "YES\n" << hola << " " << hola << ln; return 0;} 
    vi p(n+1, -1);
    solve(adj, p, n);

    return 0;
}