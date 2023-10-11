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

int numDigitos(int n){
    int ans = 0;

    while (n>0){
        ++ans; n/=10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        priority_queue<int> a, b;
        for (int i = 0; i<n; i++) {int x; cin >> x; a.push(x);}
        for (int i = 0; i<n; i++) {int x; cin >> x; b.push(x);}
        ll ans = 0;
        while (!a.empty()){
            int may1 = a.top();
            int may2 = b.top();
            if (may1 == may2) {a.pop(); b.pop();}
            else if (may1>may2) {a.pop(); a.push(numDigitos(may1)); ++ans;}
            else {b.pop(); b.push(numDigitos(may2)); ++ans;}
        }

        cout << ans << ln;

    }

    return 0;
}