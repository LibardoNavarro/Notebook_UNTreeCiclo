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

void bfs(vector<vi> &adj, vi &d, vi &horror){
    queue<int> q;
    for (int ho : horror) {q.push(ho); d[ho] = 0;}
    while(!q.empty()){
        int nodo = q.front(); q.pop();
        for (int i = 0; i<(int)adj[nodo].size(); i++){
            if (d[adj[nodo][i]] == INF){
                d[adj[nodo][i]] = d[nodo] + 1;
                q.push(adj[nodo][i]);
                }
            }
        }
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        int n, h, l; cin >> n >> h >> l;
        vector<vi> adj(n);
        vi horror(h);
        for (int i = 0; i<h; i++) cin >> horror[i];
        for (int i = 0; i<l; i++){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vi d(n, INF);
        bfs(adj, d, horror);
        ll mayor = -INF;
        ll ans = 0;
        for (int i = 0; i<n; i++){
            if (d[i]>mayor){
                mayor = d[i];
                ans = i;
            }
        }
        cout << ans << ln;
    }
    
    return 0;
}