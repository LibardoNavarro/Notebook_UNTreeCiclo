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

void dijkstra(vector<vll> &adj, int s, int n, int k){
    vector<priority_queue<ll>> dist(n+1);
    for (int i = 1; i<=n; i++){
        for (int j = 0; j<k; j++) dist[i].push(INFL);
    }
    dist[1].push(0LL);
    dist[1].pop();
    priority_queue<pll, vll, greater<pll> > pq; pq.push(pll(0LL, s));
    while(!pq.empty()){
        pll front = pq.top(); pq.pop();
        ll d = front.first, u = front.second;
        if (d > dist[u].top()) continue;

        for (int j = 0; j < (int)adj[u].size(); j++){
            pll v = adj[u][j];
            if (d + v.second < dist[v.first].top()){
                dist[v.first].pop();
                dist[v.first].push(d + v.second);
                pq.push(pll(d + v.second, v.first));
            }
        }
    }
    vl ans(k);
    int z = k;
    while (!dist[n].empty()){
        --z;
        ans[z] = dist[n].top();
        dist[n].pop();
    }

    for (ll i : ans) cout << i << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m, k; cin >> n >> m >> k;

    vector<vll> adj(n+1);

    for (int i = 0; i<m; i++){
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijkstra(adj, 1, n, k);

    return 0;
}