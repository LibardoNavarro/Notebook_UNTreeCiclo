#include <bits/stdc++.h>
#define int long long
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
const double EPS = 1e-9;
int dirx[4] = {0, -1, 1, 0};
int diry[4] = {-1, 0, 0, 1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
vi pos;

int nullValue = INFL;

struct nodeST{
    nodeST *left, *right;
    int l, r; ll value, lazy;

    nodeST(vi &v, int l, int r) : l(l), r(r){
        int m = (l+r)>>1;
        lazy = 0;
        if (l!=r){
            left = new nodeST(v, l, m);
            right = new nodeST(v, m+1, r);
            value = opt(left->value, right->value);
        }
        else{
            value = v[pos[l]];
        }
    }

    ll opt(ll leftValue, ll rightValue){
        return min(leftValue, rightValue);
    }

    void propagate(){
        if (lazy){
            value += lazy;
            if (l!=r){
                left->lazy += lazy, right->lazy += lazy;
            }
            lazy = 0;
        }
    }

    ll get(int i, int j){
        propagate();
        if (l>=i && r<=j) return value;
        if (l>j  || r<i) return nullValue;

        return opt(left->get(i, j), right->get(i, j));
    }

    void upd(int i, int j, int nv){
        propagate();
        if (l>j  || r<i) return;
        if (l>=i && r<=j){
            lazy += nv;
            propagate();
            return;
        }

        left->upd(i, j, nv);
        right->upd(i, j, nv);

        value = opt(left->value, right->value);
    }

    void upd(vi &ans, int i){
        propagate();
        if (value>0) return;
        if (l==r){
            ans[pos[l]]=i;
            value = INFL;
            return;
        }
        left->upd(ans, i);
        right->upd(ans, i);
        value = opt(left->value, right->value);
    }
};

vi izq, der;
int a = 0;

void dfs(vector<vi> &adj, int u){
    izq[u]=++a;
    pos[a] = u;
    for (int i : adj[u]) dfs(adj, i);
    der[u]=a;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi v(n+1);
    vi ans(n+1);
    v[0] = INFL;
    for (int i = 1; i<=n; i++) {cin >> v[i]; ans[i] = -1;}

    vector<vi> adj(n+1);
    vi grado(n+1);
    izq.resize(n+1);
    der.resize(n+1);
    pos.resize(n+1);

    for (int i = 1; i<=n-1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        grado[y]++;
    }

    for (int i=1; i<=n; i++){
        if (!grado[i]) dfs(adj, i);
    }

    nodeST st(v, 0, n);

    for (int i = 1; i<=q; i++){
        int x, y; cin >> x >> y;
        int z = y/(der[x]-izq[x]+1);
        if (izq[x] != der[x]){
            st.upd(izq[x]+1, der[x], -z);
        }
        z += y %(der[x]-izq[x]+1);
        st.upd(izq[x], izq[x], -z);
        st.upd(ans, i);
    }
    // for (int i = 1; i<=n; i++) cout << izq[i] << " ";
    // cout << "\n";
    // for (int i = 1; i<=n; i++) cout << der[i] << " ";
    // cout << "\n";
    // for (int i = 1; i<=n; i++) cout << pos[i] << " ";
    // cout << "\n";
    
    for (int i = 1; i<=n; i++) cout << ans[i] << "\n";
    
    return 0;
}