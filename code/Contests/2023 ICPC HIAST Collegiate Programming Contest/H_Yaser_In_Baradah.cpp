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

ll nullValue = INFL;

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
        return min(leftValue, rightValue);
    }

    ll get(int i, int j){
        if (l>=i && r<=j) return value;
        if (l>j  || r<i) return nullValue;

        return opt(left->get(i, j), right->get(i, j));
    }

    void upd(int k, ll nv){
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
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        vl v(n+1);
        vl p(n+1);
        ll maxi = -INFL;
        for (ll i = 1; i<=n; i++){
            cin >> v[i];
            p[i] = i;
            maxi = max(maxi, v[i]);
        }

        nodeST st(p, 0, n);

        int q; cin >> q;
        cout << maxi << ln;
        while (q--){
            int i; cin >> i;
            st.upd(i, INFL);
            ll padre = st.get(i+1, n);
            v[padre] += v[i];
            maxi = max(v[padre], maxi);
            cout << maxi << ln;
            v[i] = 0;
        }
        
    }
    
    return 0;
}