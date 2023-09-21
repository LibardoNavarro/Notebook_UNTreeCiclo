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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;

        ll ans = 0;
        vi v(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'B') {
                if (i < n - 1) v[i] = v[i + 1] + 1;
                else v[i] = 1;
            }
        }

        int i = 0;
        while (i < n) {
            if (s[i] == 'W')  {i++; continue;}
            int j = min(i + k - 1, n - 1);
            int maxi = v[i];
            while (j < n - 1 && j - i + 1 < k) {
                j++;
                maxi = max(maxi, v[j]);
            }
            ans++;
            i = j + 1;
        }
        cout << ans << ln;
    }
    
    return 0;
}