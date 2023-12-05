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

void dijkstra(vector<vll> &adj, vl &dist, int s, int g){
    dist[s] = 0;
    priority_queue<pll, vll, greater<pll> > pq; pq.push(pll(0LL, s));
    while(!pq.empty()){
        pll front = pq.top(); pq.pop();
        ll d = front.first, u = front.second;
        if (d > dist[u]) continue;

        for (int j = 0; j < (int)adj[u].size(); j++){
            pll v = adj[u][j];
            if (v.first == g) continue;
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(pll(dist[v.first], v.first));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;
    int p, g; cin >> p >> g;

    vector<vll> adj(n+1);

    for (int i = 0; i<m; i++){
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vl d1(n+1, INFL);
    dijkstra(adj, d1, p, 0);

    vl d2(n+1, INFL);
    dijkstra(adj, d2, p, g);
    bool bo = false;
    for (int i = 1; i<=n; i++){
        if (d1[i] == 2 * d1[g] && d2[i] > d1[i]) {bo = true; cout << i << " ";}
    }

    if (!bo) cout << '*' << ln;

    return 0;
}