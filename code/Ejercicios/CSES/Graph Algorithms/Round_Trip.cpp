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

vector<bool> visited;
vi parent;
int inicio_ciclo, final_ciclo;

bool dfs(vector<vi> &adj, int s){
    visited[s] = true;
    for (int v : adj[s]){
        if (!visited[v]){
            parent[v] = s;
            if (dfs(adj, v)) return true;
        }
        else if (parent[s] != v) {
            inicio_ciclo = v;
            final_ciclo = s;
            return true;
        }
    }
    return false;
}

void printPath(int s, int t, int &c, vi &ans){
    if (s == t) {ans.push_back(s); c+=2; return;}
    printPath(s, parent[t], c, ans);
    ans.push_back(t); c++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;

    vector<vi> adj(n+1);

    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited.assign(n+1, false);
    parent.assign(n+1, -1);
    inicio_ciclo = -1;

    for (int i = 1; i<=n; i++){
        if (!visited[i]){
            if (dfs(adj, i)) break;
        }
    }

    if (inicio_ciclo == -1) cout << "IMPOSSIBLE" << ln;
    else{
        vi ans1;
        int ans = 0;
        printPath(inicio_ciclo, final_ciclo, ans, ans1);
        cout << ans << ln;
        for (int a : ans1) cout << a << " ";
        cout << inicio_ciclo << ln;
    }

    return 0;
}