/*
El teorema que se usa aquí es que si un vértice puede alcanzar y 
ser alcanzado por todos los demás, entonces todos los vértices de 
este grafo pueden alcanzar a todos los demás.
*/

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
vector<vi> adj2;

void bfs(int v, vi &d){
    queue<int> q; q.push(v); d[v] = 0;
    while(!q.empty()){
        int nodo = q.front(); q.pop();

        for (int j = 0; j< (int) adj[nodo].size(); j++){
            if (d[adj[nodo][j]] == INT_MAX){
                d[adj[nodo][j]] = d[nodo] + 1;
                q.push(adj[nodo][j]);
            }
        }
    }
}

void bfs2(int v, vi &d){
    queue<int> q; q.push(v); d[v] = 0;
    while(!q.empty()){
        int nodo = q.front(); q.pop();

        for (int j = 0; j< (int) adj2[nodo].size(); j++){
            if (d[adj2[nodo][j]] == INT_MAX){
                d[adj2[nodo][j]] = d[nodo] + 1;
                q.push(adj2[nodo][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    adj2.resize(n+1);
    vi d(n+1, INT_MAX);

    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj2[y].push_back(x);
    }

    bool ans = true;
    int cnt = 0;
    bfs(1, d);
    for (int i = 2; i<=n; i++){
        if (d[i] == INT_MAX){
            ans = false;
            cout << "NO" << "\n" << 1 << " " << i;
        }
    }
    vi d2(n+1, INT_MAX);
    bfs2(1, d2); 
    for (int i = 2; i<=n; i++){
        if (d2[i] == INT_MAX){
            ans = false;
            cout << "NO" << "\n" << i << " " << 1;
        }
    }
    if (ans) cout << "YES";
}