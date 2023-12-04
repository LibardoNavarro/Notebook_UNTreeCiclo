#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const double EPS  = 1e-9;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

vi h;
vector<vi> queries;
map<ii, int> ans;
map<int, int> indices;

const int nax = 1e5+10;
const int L = 24;
int timer, up[nax][L+1], n;
int in[nax], out[nax];

void dfs1(int u, int p, vector<vi> &adj){
    in[u] = ++timer;
    up[u][0] = p;
    for(int i=1; i<= (int)L; ++i) up[u][i] = up[up[u][i-1]][i-1];
    for(int v: adj[u]){
        if(v==p) continue;
        dfs1(v,u, adj);
    }
    out[u] = ++timer;
}
bool anc(int u, int v){
    return in[u]<= in[v] && out[u]>= out[v];
}
void solve(int root, vector<vi> &adj){
    timer = 0;
    dfs1(root,root, adj);
}
int lca(int u, int v){
    if(anc(u,v)) return u;
    if(anc(v,u)) return v;
    for(int i= L; i>=0; --i){
        if(!anc(up[u][i],v))
        u = up[u][i];
    }
    return up[u][0];
}

int nullValue = 0;

struct nodeST{
    nodeST *left, *right;
    int l, r; ll value;

    nodeST(int l, int r) : l(l), r(r){
        int m = (l+r)>>1;
        if (l!=r){
            left = new nodeST(l, m);
            right = new nodeST(m+1, r);
            value = opt(left->value, right->value);
        }
        else{
            value = 0;
        }
    }

    ll opt(ll leftValue, ll rightValue){
        return leftValue + rightValue;
    }

    ll get(int i, int j){
        if (l>=i && r<=j) return value;
        if (l>j  || r<i) return nullValue;

        return opt(left->get(i, j), right->get(i, j));
    }

    void upd(int k, int nv){
        if (l>k  || r<k) return;
        if (l>=k && r<=k){
            value += nv;
            return;
        }

        left->upd(k, nv);
        right->upd(k, nv);

        value = opt(left->value, right->value);
        
    }
};

void dfs(vector<vi> &adj, vector<bool> &vis, nodeST &st, int u){
    vis[u] = true;
    st.upd(indices[h[u]], 1);
    for (int qu : queries[u]){
        ans[{u, qu}] = st.get(0, indices[qu]);
        // cout << "nodo " << u << " menores que " << qu << ": " << st.get(0, indices[qu]) << ln;
    }
    for (int v : adj[u]){
        if (!vis[v]) dfs(adj, vis, st, v);
    }
    st.upd(indices[h[u]], -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, q; cin >> n >> q;

    h.resize(n);
    for (int i = 0; i<n; i++) cin >> h[i];

    vector<vi> adj(n);
    for (int i = 0; i<n-1; i++){
        int u, v; cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(0, adj);

    vector<pair<ii, int>> queries1(q);

    set<int> h1(all(h));

    queries.assign(n, vi());

    for (int i = 0; i<q; ++i){
        int a, b, x; cin >> a >> b >> x; --a; --b;
        queries[a].push_back(x);
        queries[b].push_back(x);
        queries[lca(a, b)].push_back(x);
        h1.insert(x);
        queries1[i] = {{a, b}, x};
    }

    int i1 = 0;
    for (int values : h1) {indices[values] = i1; ++i1;}

    nodeST st(0, sz(h1)-1);

    vector<bool> vis(n, 0);
    dfs(adj, vis, st, 0);
    for (pair<ii, int> qu: queries1){
        int a = qu.first.first, b = qu.first.second, x = qu.second;
        int lca1 = lca(a, b);
        cout << ans[{a, x}] + ans[{b, x}] - 2*ans[{lca1, x}]  + (h[lca1]<= x? 1 : 0) << ln;
    }

    return 0;
}