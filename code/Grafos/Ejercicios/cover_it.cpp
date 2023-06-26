#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    for (int w = 0; w<t; w++){
        int n, m; cin >> n >> m;
        vector<vi> adj(n+1);
        for (int i = 0; i<m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        queue<int> q; q.push(1);
        vi d(n+1, INT_MAX); d[1] = 0;
        d[0] = 0;
        while(!q.empty()){
            int nodo = q.front(); q.pop();
            for (int i = 0; i<(int)adj[nodo].size(); i++){
                if (d[adj[nodo][i]] == INT_MAX){
                    d[adj[nodo][i]] = d[nodo] + 1;
                    q.push(adj[nodo][i]);
                }
            }
        }
        vi lpares;
        vi limpares;
        int pares = 0;
        int impares = 0;
        for (int i = 1; i<=n; i++){
            if (d[i] % 2 == 0){
                pares++;
                lpares.push_back(i);
            }
            else{
                impares++;
                limpares.push_back(i);
            }
        }

        int a = min(impares, pares);

        if (a == impares){
            cout << impares << "\n";
            for (int j : limpares) cout << j << " ";
        }
        else{
            cout << pares << "\n";
            for (int j : lpares) cout << j << " ";
        }

        cout << "\n";

    }
}