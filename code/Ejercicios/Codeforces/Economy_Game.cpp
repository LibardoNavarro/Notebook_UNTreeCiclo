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

    ll n; cin >> n;

    for (ll a = 0; a<=811; a++){
        for (ll b = 0; b<=8101; b++){
            double c = (n - 1234567*a - 123456*b) / 1234;
            if (c == (ll) c && 1234567*a + 123456*b + c*1234 == n && c>=0) {cout << "YES" << "\n"; return 0;}
        }
    }
    cout << "NO" << "\n";
    
    return 0;
}