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
// vi ciclo;
int dias = 0;
int x = 0;
map<int, int> dic;
vi ans;

void dfs(int v, int libro){
    dfs_num[v] = 1;
    ans[v] = x;
    dias++;
    for (int i = 0; i < (int) adj[v].size(); i++){ 
        if (adj[v][i] == libro){
            dic[x] = dias;
            return;
        }
        if (dfs_num[adj[v][i]] != 1){
            dfs(adj[v][i], libro);
        }

    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    x = 0;
    int q; cin >> q;
    for (int z = 0; z<q; z++){
        int n; cin >> n;
        dias = 0;
        adj = vector<vi>(n+1);
        dfs_num.resize(n+1);
        ans = vi(n+1);
        vi libros(n+1);
        dic = map<int, int>();
        for (int i = 1; i<=n; i++){
            int a; cin >> a;
            adj[i].push_back(a);
            libros[i] = a;
            dfs_num[i] = 0;
        }
        for (int i = 1; i<=n; i++){
            if (ans[i] == 0){
                x++;
                dias = 0;   
                dfs(libros[i], libros[i]);
            }
        }
        for (int i = 1; i<=n; i++) cout << dic[ans[i]] << " ";
        cout << "\n";
    }
}