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
const double EPS  = 1e-9;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

ll nullValue = (1<<30) - 1;

struct nodeST{
    nodeST *left, *right;
    int l, r; ll value;

    nodeST(vl &v, int l, int r) : l(l), r(r){
        int m = (l+r)>>1;
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
        return leftValue & rightValue;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        vl v(n+1);
        for (int i = 1; i<=n; i++) cin >> v[i];
        int q; cin >> q;
        nodeST st(v, 0, n);
        while (q--){
            int l, k; cin >> l >> k;
            int low = l;
            int high = n;
            int ans = 0;
            while(low <= high){
                
                int mid = low + (high - low) / 2;
                if(st.get(l, mid) >= k){
                    low = mid+1;
                }
                else{
                    ans = mid;
                    high = mid-1;
                }
            }
            if (ans == 0) cout << n << " ";
            else if (ans-1>=l && st.get(l, ans-1) >= k) cout << ans-1 << " ";
            else cout << -1 << " ";
        }
        cout << ln;
    }

    return 0;
}