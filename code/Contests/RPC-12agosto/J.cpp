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

//O(log10 n) n == max(a, b)
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
//gcd(a, b, c) = gcd(a, gcd(b, c))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll ds, ys; cin >> ds >> ys;
    ll dm, ym; cin >> dm >> ym;
    ll ans = 0;
    for (int i = 0; i<5000; i++){
        ans++;
        if ((ds+ans) % ys == 0 && (dm+ans)%ym == 0){
            cout << ans << "\n";
            break;
        }
    }
    
    return 0;
}