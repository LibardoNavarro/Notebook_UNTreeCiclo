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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        vi a(n);
        for (int i = 0; i<n; i++) cin >> a[i];
        vi b(n);
        for (int i = 0; i<n; i++) cin >> b[i];
        for (int i = 0; i<n; i++){
            int ind = lower_bound(all(b), a[i]) - b.begin();
            cout << b[ind] - a[i] << " ";
        }
        cout << ln;
        vi ans(n);
        int ans1 = n;
        for (int i = n-1; i>=0; i--){
            ans[i] = ans1-1;
            int ind = lower_bound(all(b), a[i]) - b.begin();
            if (i == ind){
                ans1 = i;
            }
        }
        for (int i = 0; i<n; i++) cout << b[ans[i]] - a[i] << " ";
        cout << ln;
    }

    return 0;
}