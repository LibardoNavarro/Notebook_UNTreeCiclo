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
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vi> adj(2 * (10e4 +1));
    adj[n].push_back(n*2);
    adj[n].push_back(n-1);

    queue<int> q; q.push(n);
    vi d(2 * (10e4 +1), INT_MAX); d[n] = 0;
    while(!q.empty()){
        int nodo = q.front(); q.pop();
        for (int i = 0; i<(int)adj[nodo].size(); i++){
            if (adj[nodo][i] < 0 || adj[nodo][i] >= 2 * (10e4 +1)) continue;
            if (d[m] != INT_MAX) break;
            if (d[adj[nodo][i]] == INT_MAX){
                d[adj[nodo][i]] = d[nodo] + 1;
                adj[adj[nodo][i]].push_back(adj[nodo][i] * 2);
                adj[adj[nodo][i]].push_back(adj[nodo][i] - 1);
                q.push(adj[nodo][i]);
            }
        }
        if (d[m] != INT_MAX) break;
    }

    cout << d[m];
}