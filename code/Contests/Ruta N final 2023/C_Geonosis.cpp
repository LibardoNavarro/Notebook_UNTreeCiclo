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

void dijkstra(vector<vector<pair<int, ll>>> &adj, vl &dist, int s){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq; pq.push({0LL, s});
    dist[s] = 0LL;
    while(!pq.empty()){
        pair<ll, ll> front = pq.top(); pq.pop();
        ll d = front.first, u = front.second;
        if (d > dist[u]) continue;

        for (int j = 0; j < (int)adj[u].size(); j++){
            ii v = adj[u][j];
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
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
        int n; cin >> n;
        vector<vl> adj(n, vl(n, 0));
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++) {
                cin >> adj[i][j];
                if (!adj[i][j]) adj[i][j] = INFL;
            }
        }
        vi v(n);
        for (int i = 0; i<n; i++) cin >> v[i];
        vi activos;
        vector<vector<pair<int, ll>>> adj1(n);
        ll ans = 0;
        for (int z = n-1; z>=0; z--){
            activos.push_back(v[z]);
            for (int i : activos){
                if (v[z] != i) {
                    if (adj[v[z]][i] != INFL) adj1[v[z]].push_back({i, adj[v[z]][i]});
                    if (adj[i][v[z]] != INFL) adj1[i].push_back({v[z], adj[i][v[z]]});
                }
            }
            vl dist(n, INFL);
            dijkstra(adj1, dist, v[z]);
            for (int i = 0; i<n; i++) adj[v[z]][i] = min(dist[i], adj[v[z]][i]);
            for (int i : activos){
                for (int j : activos){
                    adj[i][v[z]] = min(adj[i][v[z]], adj[i][j] + adj[j][v[z]]);
                }
            }

            for (int i : activos){
                for (int j : activos){
                    adj[i][j] = min(adj[i][j], adj[i][v[z]] + adj[v[z]][j]);
                }
            }
            for (int i : activos){
                for (int j : activos){
                    if (adj[i][j] != INFL) ans+=adj[i][j];
                }
            }
        }
        cout << ans << ln;
    }
    
    return 0;
}