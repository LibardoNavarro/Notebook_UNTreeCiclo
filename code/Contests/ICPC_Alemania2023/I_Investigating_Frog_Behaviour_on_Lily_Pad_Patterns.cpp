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
const char ln = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vi v(n);
    set<int> x;
    int m = 0;
    for (int i = 0; i<n; i++){
        int a; cin >> a;
        x.insert(a);
        v[i] = a;
        m = max(m, a);
    }
    set<int> s;
    for (int i = 1; i <= m+1; i++){
        if (!x.count(i)) s.insert(i);
    }

    int q; cin >> q;

    for (int i = 0; i<q; i++){
        int a; cin >> a; a--;
        //for (int z : s) cout << z << " ";
        //cout << "\n";
        int ans = *s.upper_bound(v[a]);
        if (ans == *s.rbegin()){
            s.insert(ans+1);
        }
        s.erase(ans); s.insert(v[a]);

        v[a] = ans;
        cout << ans << "\n";

    }

    //for (int z : s) cout << z << " ";

    return 0;
}