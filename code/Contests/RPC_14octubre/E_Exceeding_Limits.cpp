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
const double EPS  = 1e-6;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';
typedef pair<int, ii> piii;

double dijkstra(vector<vector<piii>> &adj, int s, int V, double x){
    vector<double> dist(V+1, INFL); dist[s] = 0.0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq; pq.push({0.0, s});
    while(!pq.empty()){
        pair<double, int> front = pq.top(); pq.pop();
        double d = front.first; int u = front.second;
        if (d > dist[u]) continue;

        for (int j = 0; j < (int)adj[u].size(); j++){
            piii par = adj[u][j];
            int v = par.first, l = par.second.first, vel = par.second.second;
            double w = ((double) l / (vel+x));
            // cout << "W: " << w << " "<< l << " " << vel << " " << x << ln;
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[V];
}

double bs(vector<vector<piii>> &adj, double l, double r, double limite, int n){
    double ultimo=0;
    while(r-l>EPS){
        double mid=l+(r-l)/2.0;
        if(dijkstra(adj, 1, n, mid)>limite){
            l=mid;
        }else{
            ultimo=mid;
            r=mid;
        }
    }  
    return ultimo; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(7) << fixed;
    int n, m, t; cin >> n >> m >> t;
    vector<vector<piii>> adj(n+1);
    for (int i = 0; i<m; i++){
        int a, b, l, v; cin >> a >> b >> l >> v;
        adj[a].push_back({b, {l, v}});
        adj[b].push_back({a, {l, v}});
    }
    if (dijkstra(adj, 1, n, 0) <= t) cout << 0 << ln;
    else cout<<bs(adj, 0, 1e10, t, n)<<"\n";
    return 0;
}