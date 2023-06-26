#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

class UnionFind{
    private: vi p, rank;
    public:
        UnionFind(int N){
            rank.assign(N, 0);
            p.assign(N, 0);
            for (int i = 0; i<N; i++) p[i] = i;
        }
        int findSet(int i) {return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
        bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}
        void unionSet(int i, int j){
            if (!isSameSet(i, j)){
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y]) p[y] = x;
                else {p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, ii>> adj;
    vector<string> palabras(n);

    for (int i = 0; i<n; i++){
        string a; cin >> a;
        palabras[i] = a;
    }

    for (int i = 0; i<n; i++){
        string palabra1 = palabras[i];
        for (int j = 0; j<n; j++){
            string palabra2 = palabras[j];
            if (palabra1 != palabra2){
                ll w = 0;
                for (int k = 0; k<m; k++){
                    w += abs(int(palabra1[k]) - int(palabra2[k]));
                }
                adj.push_back(make_pair(w, ii(i, j)));
            }
        }
    }

    int ans = 0;

    sort(adj.begin(), adj.end());

    m = n * (n-1);

    int mst_costo = 0, tomados = 0;
    UnionFind UF(n);
    for (int i = 0; i<m && tomados < n-1; i++){
        pair<int, ii> front = adj[i];
        if (!UF.isSameSet(front.second.first, front.second.second)){
            tomados++;
            mst_costo += front.first;
            ans = max(front.first, ans);
            UF.unionSet(front.second.first, front.second.second);
        }
    }
    cout << ans << "\n";
}