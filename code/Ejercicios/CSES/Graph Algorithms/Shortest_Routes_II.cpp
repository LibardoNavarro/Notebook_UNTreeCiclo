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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m, q; cin >> n >> m >> q;
    vector<vl> adj(n, vl(n, INFL));
    for (int i = 0; i<n; i++) adj[i][i] = 0LL;

    for (int i = 0; i<m; i++){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        adj[a][b] = min(adj[a][b], c); adj[b][a] = min(adj[b][a], c);
    }

    for (int k = 0; k<n; k++){
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                if (adj[i][k] < INFL && adj[k][j] < INFL){
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    for (int i = 0; i<q; i++){
        int a, b; cin >> a >> b; a--, b--;
        cout << (adj[a][b]>=INFL?-1:adj[a][b]) << ln;
    }
    
    return 0;
}