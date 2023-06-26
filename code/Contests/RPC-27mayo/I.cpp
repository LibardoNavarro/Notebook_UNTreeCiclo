#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((ll) arr.size())
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<long long> vl;
const ll INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9+7;
ll dirx[4] = {0,-1,1,0};
ll diry[4] = {-1,0,0,1};
ll dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
ll dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll spfa(vector<vii>& adj, ll s, ll n) {
    vl d(n+1, INFL);
    vector<bool> inqueue(n, false);
    queue<ll> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                }
            }
        }
    }
    return d[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<vii> adj(n+2);
    for(ll i = 1; i<=n; i++){
        ll c; cin >> c;
        ll dwd = min(m, n-i+1);
        for (ll j = 1; j<=dwd; j++){
            ll w; cin >> w;
            ii a = {i+j, c-w};
            adj[i].push_back(a);

        }
    }
    cout << spfa(adj, 1, n+1) << "\n";
}