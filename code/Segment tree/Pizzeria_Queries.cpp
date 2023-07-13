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

int nullValue = INF;

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
        return min(leftValue, rightValue);
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
            value += nv;
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

    vi p(n);
    for (int i = 0; i<n; i++) cin >> p[i];

    vi p1(n);
    for (int i = 0; i<n; i++) p1[i]=p[i]+i+1;

    vi p2(n);
    for (int i = 0; i<n; i++) p2[i]=p[i]-i-1;

    nodeST st1(p1, 0, n-1);
    nodeST st2(p2, 0, n-1);

    for (int i = 0; i<q; i++){
        int o, k; cin >> o >> k;
        if (o == 1){
            k--;
            int x; cin >> x;
            int v = x - p[k];
            p[k] += v;
            st1.upd(k, v);
            st2.upd(k, v);
        }
        else{
            cout << min(st1.get(k-1, n-1) - k, st2.get(0, k-1) + k) << "\n";
        }
    }
    
    return 0;
}