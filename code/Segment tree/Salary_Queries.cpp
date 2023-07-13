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

int nullValue = 0;
 
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi p(n);
    unordered_map<int, int> m;
    for (int i = 0; i<n; i++) {cin >> p[i]; m[p[i]]++;}
    set<int> hola(p.begin(), p.end());

    vector<pair<char, ii>> entradas;

    for (int i = 0; i<q; i++){
        char c; int a, b; cin >> c >> a >> b;
        entradas.push_back({c, {a, b}});
        if (c == '!'){
            p.push_back(b);
        }
        else{
            p.push_back(a);
            p.push_back(b);
        }
    }

    vi p1(p.begin(), p.end());
    sort(p1.begin(), p1.end());
    p1.erase(unique(p1.begin(), p1.end()), p1.end());
    int y = sz(p1);

    vl s(y);
    for (int i = 0; i<y; i++){
        s[i] = m[p1[i]];
    }

    nodeST st(s, 0, y-1);

    for (int i = 0; i<q; i++){
        char c = entradas[i].first; 
        int a = entradas[i].second.first, b = entradas[i].second.second;
        if (c == '!'){
            a--;
            int index = lower_bound(p1.begin(), p1.end(), p[a]) - p1.begin();
            st.upd(index, -1);
            int index1 = lower_bound(p1.begin(), p1.end(), b) - p1.begin();
            st.upd(index1, 1);
            p[a] = b;
        }
        else{
            int index = lower_bound(p1.begin(), p1.end(), a) - p1.begin();
            int index1 = lower_bound(p1.begin(), p1.end(), b) - p1.begin();
            cout << st.get(index, index1) << "\n";
        }
    }
    
    return 0;
}