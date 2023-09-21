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

ll solve (vl v, ll h, ll n){
    ll agua = 0;
    for (int i = 0; i<n; i++){
        if (v[i] < h) agua += h-v[i];
    }
    return agua;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int t; cin >> t;

    while (t--){
        ll n, x; cin >> n >> x;
        vl v(n);
        for (int i = 0; i<n; i++) cin >> v[i];

        ll low = 0;
        ll high = 5e12;
        ll ans = 1;   
        while(low <= high){
            
            ll mid = low + (high - low) / 2;
            ll a = solve(v, mid, n);
            if(a <= x){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        cout << ans-1 << ln;


    }
    
    return 0;
}