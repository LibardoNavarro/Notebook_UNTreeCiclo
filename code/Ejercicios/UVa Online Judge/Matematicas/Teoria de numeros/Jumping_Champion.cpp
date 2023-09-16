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

vl p;
bitset<1000013> bs;
void sieve(ll n){
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i<=n; i++){
        if (bs[i]){
            for (ll j=i*i; j<=n; j+=i) bs[j] = 0;
            p.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    sieve(1000003);

    int t; cin >> t;

    while (t--){
        int l, u; cin >> l >> u;
        int p1 = lower_bound(all(p), l) - p.begin();
        int p2 = (upper_bound(all(p), u) - p.begin()) - 1;
        map<int, int> m;
        for (int i = p1; i<=p2-1; i++) m[p[i+1] - p[i]]++;
        bool b = false;
        int ans = 0;
        for (auto d : m){
            if (d.second == m[ans]) b = false;
            else if (d.second > m[ans]) {b = true; ans = d.first;}
        }
        
        if (b) cout << "The jumping champion is " << ans << ln;
        else cout << "No jumping champion" << ln;
    }
    
    return 0;
}