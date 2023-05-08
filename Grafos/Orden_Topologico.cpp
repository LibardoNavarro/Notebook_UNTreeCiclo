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
vi ts;

void dfs(int v){
    dfs_num[v] = 1;
    for (int i = 0; i < (int) adj[v].size(); i++){ 

        if (dfs_num[adj[v][i]] != 1){
            dfs(adj[v][i]);
        }

    }
    ts.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    dfs_num.resize(n+1);

    for (int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i<=n; i++){
        if (dfs_num[i] != 1){
            dfs(i);
        }
    }

    reverse(ts.begin(), ts.end());

    return 0;
}