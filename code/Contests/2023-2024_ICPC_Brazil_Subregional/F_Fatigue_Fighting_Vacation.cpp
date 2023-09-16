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
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll d, c, r; cin >> d >> c >> r;

    vi v(c);
    for (int i = 0; i<c; i++) cin >> v[i];
    for (int i = 0; i<r; i++) {ll a; cin >> a; d+=a;}
    ll ans = r;
    for (int i = 0; i<c; i++){
        if (d>=v[i]){
            ans++;
            d -= v[i];
        }
        else break;
    }
    cout << ans << "\n";
}