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

vi pos;
ll nullValue = 0LL;

struct nodeST{
    nodeST *left, *right;
    int l, r; ll value, lazy;

    nodeST(vl &v, int l, int r) : l(l), r(r){
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
        return leftValue + rightValue;
    }

    void propagate(){
        if (lazy){
            value += lazy * (r-l+1);
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
};

vi izq, der;
int a = 0;

void dfs(vector<vi> &adj, int u){
    izq[u]=++a;
    int temp = a;
    pos[a] = u;
    for (int i : adj[u]) dfs(adj, i);
    der[u]=a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        a = 0;
        int q; cin >> q;
        int n = 1;
        vii aristas;
        vll queries;
        vector<pair<int, pll>> todo;
        for (int i = 0; i<q; i++){
            int o; cin >> o;
            if (o == 1){
                int v; cin >> v;
                aristas.push_back({v, ++n});
                todo.push_back({o, {v, n}});
            }
            else{
                ll v, x; cin >> v >> x;
                queries.push_back({v, x});
                todo.push_back({o, {v, x}});
            }
        }
        vector<vi> adj(n+1);
        izq.assign(n+1, 0);
        der.assign(n+1, 0);
        pos.assign(n+1, 0);
        vl restar(n+1, 0LL);

        for (ii e : aristas){
            adj[e.first].push_back(e.second);
        }
        dfs(adj, 1);
        vl v1(n+1, 0LL);
        nodeST st1(v1, 0, n);

        for (auto e : todo){
            if (e.first == 1){
                int v = e.second.second;
                restar[v] = st1.get(izq[v], izq[v]);
            }
            else{
                int v = e.second.first; ll x = e.second.second;
                st1.upd(izq[v], der[v], x);
            }
        }

        vl v(n+1, 0LL);
        nodeST st(v, 0, n);

        for (pll c : queries){
            int v = c.first; ll x = c.second;
            st.upd(izq[v], der[v], x);
        }
        for (int i = 1; i<=n; i++){
            cout << st.get(izq[i], izq[i]) - restar[i] << " ";
        }
        cout << ln;
    }

    return 0;
}