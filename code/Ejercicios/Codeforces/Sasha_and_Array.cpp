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
const double EPS = 1e-9;
int dirx[4] = {0, -1, 1, 0};
int diry[4] = {-1, 0, 0, 1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll mod(ll a, ll m) {return ((a%m)+m) % m;}

const int MAXN = 2;
ll temp[MAXN][MAXN] = {{0LL, 0LL}, {0LL, 0LL}};

struct matrix {
    int r, c;
    ll m[MAXN][MAXN];

    matrix() {}
    matrix(int r, int c, const ll mat[MAXN][MAXN]) : r(r), c(c) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                m[i][j] = mat[i][j];
            }
        }
    }

    matrix operator*(const matrix &b) {
        matrix ans(this->r, b.c, temp);

        for (int i = 0; i < this->r; i++) {
            for (int k = 0; k < b.r; k++) {
                if (m[i][k] == 0) continue;
                for (int j = 0; j < b.c; j++) {
                    ans.m[i][j] += mod(m[i][k], MOD) * mod(b.m[k][j], MOD);
                    ans.m[i][j] = mod(ans.m[i][j], MOD);
                }
            }
        }
        return ans;
    }

    matrix operator+(const matrix &b) {
        matrix ans(this->r, b.c, temp);
        for (int i = 0; i < this->r; i++) {
            for (int j = 0; j < this->c; j++) {
                ans.m[i][j] = mod(m[i][j], MOD) + mod(b.m[i][j], MOD);
                ans.m[i][j] = mod(ans.m[i][j], MOD);
            }
        }
        return ans;
    }
};

matrix pow(matrix b, ll p) {
    matrix ans(b.r, b.c, temp);
    for (int i = 0; i < b.r; i++) ans.m[i][i] = 1;
    while (p) {
        if (p & 1) {
            ans = ans * b;
        }
        b = b * b;
        p >>= 1;
    }
    return ans;
}

matrix nullValue(2, 2, temp);
ll identidad[MAXN][MAXN] = {{1LL, 0LL}, {0LL, 1LL}};
matrix iden(2, 2, identidad);
ll fibonacci[MAXN][MAXN] = {{1LL, 1LL}, {1LL, 0LL}};
matrix f(2, 2, fibonacci);

struct nodeST{
    nodeST *left, *right;
    int l, r; matrix m, lazy;

    nodeST(vl &v, int l, int r) : l(l), r(r){
        int mid = (l+r)>>1;
        lazy = iden;
        if (l!=r){
            left = new nodeST(v, l, mid);
            right = new nodeST(v, mid+1, r);
            m = opt(left->m, right->m);
        }
        else{
            m = pow(f, v[l]);
        }
    }

    matrix opt(matrix leftValue, matrix rightValue){
        return leftValue + rightValue;
    }

    void propagate(){
        if (lazy.m != iden.m){
            m = m * lazy;
            if (l!=r){
                left->lazy=left->lazy*lazy, right->lazy = right->lazy*lazy;
            }
            lazy = iden;
        }
    }

    matrix get(int i, int j){
        propagate();
        if (l>=i && r<=j) return m;
        if (l>j  || r<i) return nullValue;

        return opt(left->get(i, j), right->get(i, j));
    }

    void upd(int i, int j, matrix &nv){
        propagate();
        if (l>j  || r<i) return;
        if (l>=i && r<=j){
            lazy = lazy*nv;
            propagate();
            return;
        }

        left->upd(i, j, nv);
        right->upd(i, j, nv);

        m = opt(left->m, right->m);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vl v(n);
    for (int i = 0; i<n; i++) cin >> v[i];
    nodeST st(v, 0, n-1);

    for (int i = 0; i<m; i++){
        int o, l, r; cin >> o >> l >> r;

        if (o==1){
            int x; cin >> x;
            matrix m1 = pow(f, x);
            st.upd(l-1, r-1, m1);
        }
        else cout << st.get(l-1, r-1).m[0][1] << "\n";
    }

    return 0;
}