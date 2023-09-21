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

const string abc = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, m; cin >> n >> m;

    vector<string> v(n+1);
    for (int i = 1; i<=n; i++) cin >> v[i];

    int q; cin >> q;

    while (q--){
        int a, b; cin >> a >> b;
        ll ans = 0;
        for (int i = 0; i<26; i++){
            auto ix1 = lower_bound(all(v[a]), abc[i]);
            auto ix2 = lower_bound(all(v[b]), abc[i]);
            if (ix1 == v[a].end() || ix2 == v[b].end()) continue;
            int x1 = ix1 - v[a].begin();
            int x2 = ix2 - v[b].begin();
            int y1, y2;
            if (i == 25) {
                y1 = m-1; y2 = m-1;
            }
            else{
                auto iy1 = upper_bound(all(v[a]), abc[i]);
                auto iy2 = upper_bound(all(v[b]), abc[i]);
                if (iy1 == v[a].end()) y1 = m-1;
                else y1 = (iy1 - v[a].begin())-1;
                if (iy2 == v[b].end()) y2 = m-1;
                else y2 = (iy2 - v[b].begin())-1;
            }
            int ans1 = max(x1, x2), ans2 = min(y1, y2);
            if (ans1 > ans2) continue;
            else ans += ans2-ans1+1;

        }
        cout << ans << ln;
    }
    
    return 0;
}