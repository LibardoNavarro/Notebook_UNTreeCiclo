#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF 1000000000

vector<vi> adj;
vi dfs_num;
set<int> num_vecinos;
int ans = 0;
map<int, int> veces;

void dfs(int v){
    dfs_num[v] = 1;
    int vecinos = 0;
    for (int i = 0; i < (int) adj[v].size(); i++){ 
        vecinos++;
        if (dfs_num[adj[v][i]] != 1){
            dfs(adj[v][i]);
        }
    }
    num_vecinos.insert(vecinos);
    veces[vecinos]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int z = 0; z < t; z++){
        int n, m;
        cin >> n >> m;
        adj.resize(n + 1);
        dfs_num.resize(n + 1);

        int a, b;
        for (int i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(a);

        
        int x = -1, y = -1;
        int f, g;
        int d = 0;
        for (int element : num_vecinos) {
            // cout << element << " " << veces[element]<< "d\n";
             if (d == 2){
                f = element;
             }
             else if (d == 1){
                g = element;
             }
             d++;
        }
        if (num_vecinos.size() == 2){
            x = g; y = --g;
        }
        else{
            if (veces[f] == 1){
                x = f;
                y = --g;
            }
            else if (veces[g] == 1){
                x = g;
                y = --f;
            }
        }
        

        cout << x << " " << y << "\n";

        num_vecinos.clear();
        veces.clear();
        adj.clear();
        dfs_num.clear();
    }
    return 0;
}