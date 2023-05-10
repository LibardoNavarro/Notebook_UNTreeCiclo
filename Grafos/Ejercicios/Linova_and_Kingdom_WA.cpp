#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
vector<vi> adj;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    adj.resize(n+1);
    for (int i = 0; i<n-1; i++){
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

    sort(d.begin(), d.end());

    reverse(d.begin(), d.end());

    int suma = 0;

    for (int i = 0; i<k; i++){
        suma += d[i];
    }

    cout << suma;
}