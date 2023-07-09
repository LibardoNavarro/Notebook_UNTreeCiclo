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

ll nullValue = -INFL;

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
            value = v[l];
        }
    }

    ll opt(ll leftValue, ll rightValue){
        return max(leftValue,rightValue);
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

    void upd(int i, int j, ll nv){
        propagate();
        if (l>j  || r<i) return;
        if (l>=i && r<=j){
            lazy += nv;
            propagate();
            // value = nv;
            return;
        }

        left->upd(i, j, nv);
        right->upd(i, j, nv);

        value = opt(left->value, right->value);
        
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vi x(n);
    for (int i = 0; i<n; i++) cin >> x[i];

    vl prefix(n+1);
    prefix[0] = 0;
    ll suma = 0;
    for (int i = 0; i<n; i++){suma += x[i]; prefix[i+1] = suma;}

    nodeST st(prefix, 0, n);

    for (int i = 0; i<q; i++){
        int o; cin >> o;
        if (o == 1){
            ll k, u; cin >> k >> u;
            ll v = u - x[k-1];
            x[k-1] = u; 
            st.upd(k, n, v);
        }
        else{
            int a, b; cin >> a >> b;
            cout << st.get(a-1, b) - st.get(a-1, a-1) << "\n";
        }
    }
}