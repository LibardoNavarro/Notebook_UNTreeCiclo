#include <bits/stdc++.h>
using namespace std;

#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;

int dirx[4] = {0, -1, 1, 0};
int diry[4] = {-1, 0, 0, 1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

void dfs(vector<vi> &adj, int s, int len, vi vert, vi vis, int n){
    vis[s] = 1;
    vert.push_back(s);
    len++;
    for (int vecino : adj[s]){
        if (vecino == 1 && len == n){
            for (int z = 0; z<n; z++) {
                if (z == n-1) cout << vert[z];
                else cout << vert[z] << " ";
            }
            cout << ln;

        }
        else if (vis[vecino] == -1) dfs(adj, vecino, len, vert, vis, n); 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    set<int> primos = {2,3,5,7,11,13,17,19,23,29,31};
    int n = -1;
    int caso = 0;
    bool hola = false;
    while (cin >> n, n != -1){
        caso++;
        if (n % 2 == 1) continue;
        if (hola)cout << ln;
        hola = true;
        cout << "Case " << caso << ":\n";
        vector<vi> adj(n+1);
        for (int i = 1; i<=n; i++){
            for (int j = i+1; j<=n; j++){
                if (primos.count(i+j)) {adj[i].push_back(j); adj[j].push_back(i);}
            }
        }
        vi vacio, vis(n+1, -1);
        dfs(adj, 1, 0, vacio, vis, n);
        n = -1;
    }

    return 0;
}