#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF 1000000000;

vector<vi> adj;
vi dfs_num;
vi gato;
int ans = 0;

void dfs(int v, int gatos, int gatos_maximos){
    dfs_num[v] = 1;
    if (gato[v] == 1){
        gatos++;
    }
    else{
        gatos = 0;
    }
    if (gatos > gatos_maximos){
        return;
    }
    int vecinos_unvisited = 0;
    for (int i = 0; i < (int) adj[v].size(); i++){ 

        if (dfs_num[adj[v][i]] != 1){
            vecinos_unvisited++;
            dfs(adj[v][i], gatos, gatos_maximos);
        }

    }
    if (vecinos_unvisited == 0){
        ans++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    gato.resize(n+1);
    adj.resize(n+1);
    dfs_num.resize(n+1);

    for (int i = 1; i<=n; i++) cin >> gato[i];

    for (int i = 0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0, m);
    cout << ans << "\n";
    return 0;
}