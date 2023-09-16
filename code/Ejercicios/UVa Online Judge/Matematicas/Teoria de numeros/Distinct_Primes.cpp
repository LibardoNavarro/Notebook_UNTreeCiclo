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

void sieve(ll n, vl &ans1){
    vl bs(n + 1, 0);
    set<ll> ans;
    bs[0] = bs[1] = 1;
    for (ll i = 2; i<=n; i++){
        if (!bs[i]){
            for (ll j=i; j<=n; j+=i){
                bs[j]++;
                if (bs[j] >= 3) {if (!ans.count(j)) {ans.insert(j); ans1.push_back(j);}}
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    vl ans1;
    sieve(3e3, ans1);
    sort(all(ans1));
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        cout << ans1[n-1] << ln;
    }
    
    return 0;
}