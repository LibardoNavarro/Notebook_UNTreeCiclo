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
        vi p(n);
        for (int i = 0; i<n; i++) cin >> p[i];

        int r = 0;
        for (int i = 0; i<n-1; i++){
            if (p[r+1] < p[i+1]) r = i;
        }

        if (r == n-2) r = n-1;
        int l = 0;
        for (int i = r; i<n-1; i++) cout << p[i+1] << " ";
        cout << p[r] << " ";
        for (int i = r-1; i>=0; i--){
            if (p[i] < p[0]) {l = i+1; break;}
            cout << p[i] << " ";
        }

        for (int i = 0; i<l; i++){
            cout << p[i] << " ";
        }
        cout << ln;
    }

    return 0;
}