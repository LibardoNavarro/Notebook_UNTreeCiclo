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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll h, k, v, s; cin >> h >> k >> v >> s;
    ll ans = 0;
    while (h>0){
        v += s;
        v -= max(1LL, v/10);
        if (v>=k) h++;
        if (0<v && v<k) {
            h--; 
            if (h==0) v=0;
        }
        if (v<=0) {h = 0; v=0;}
        ans += v;
        if (s>0) s--;
    }

    cout << ans << "\n";
    
    return 0;
}