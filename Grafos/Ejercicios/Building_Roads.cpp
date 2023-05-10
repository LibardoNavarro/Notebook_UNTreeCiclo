#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vi> adj;
vi dfs_num;

void dfs(int v){
    dfs_num[v] = 1;
    for (int i = 0; i < adj[v].size(); i++){
        if (dfs_num[adj[v][i]] != 1){
            dfs(adj[v][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    dfs_num.resize(n+1);

    for (int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vii vert;
    int a = 0;
    int b = 0;
    for (int i = 1; i<=n; i++){
        if (dfs_num[i] != 1){
            a++;
            dfs(i);
            if (a > 1){
            ii c = {b, i};
            vert.push_back(c);
            }
            b = i;
        }
    }

    cout << vert.size() << "\n";

    for (auto i: vert){
        cout << i.first << " " << i.second << "\n";
    }

}