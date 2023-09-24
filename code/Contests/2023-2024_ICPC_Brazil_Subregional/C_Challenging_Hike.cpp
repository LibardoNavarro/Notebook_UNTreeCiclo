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

int nullValue = -INF;

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
            value = v[l];
        }
    }

    ll opt(ll leftValue, ll rightValue){
        return max(leftValue, rightValue);
    }

    ll get(int i, int j){
        if (l>=i && r<=j) return value;
        if (l>j  || r<i) return nullValue;

        return opt(left->get(i, j), right->get(i, j));
    }

    void upd(int k, int nv){
        if (l>k  || r<k) return;
        if (l>=k && r<=k){
            value = nv;
            return;
        }

        left->upd(k, nv);
        right->upd(k, nv);

        value = opt(left->value, right->value);
    }
};

void dfs(vector<vi> &adj, vi &vis, int s, int lis, vi &ans, nodeST &st, vi &likes, map<int, int> &m){
    vis[s] = 1;
    int v = st.get(m[likes[s]], m[likes[s]]);
    int v1 = st.get(0, m[likes[s]] - 1) + 1;
    st.upd(m[likes[s]], v1);
    lis = max(lis, v1);
    ans[s] = lis;
    for (int u : adj[s]){
        if (!vis[u]) {
            dfs(adj, vis, u, lis, ans, st, likes, m);
        }
    }
    st.upd(m[likes[s]], v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n; cin >> n;
    vector<vi> adj(n+1);
    for (int i = 2; i<=n; i++){
        int u; cin >> u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }

    vi likes(n+1);
    for (int i = 1;i<=n; i++) cin >> likes[i];

    vi ans(n+1, 0);
    vi vis(n+1, 0);
    set<int> s(all(likes));
    vi likes1(all(s));
    int n1 = sz(likes1);
    map<int, int>m;
    for (int i = 1; i<n1; i++) m[likes1[i]] = i;
    vi hola(n1, 0);
    nodeST st(hola, 0, n1-1);
    dfs(adj, vis, 1, 0, ans, st, likes, m);

    for (int i = 2; i<=n; i++) cout << ans[i] << " ";
    
    return 0;
}