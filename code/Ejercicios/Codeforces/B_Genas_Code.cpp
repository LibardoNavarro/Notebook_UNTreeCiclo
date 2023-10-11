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

    int n; cin >> n;

    string ans = "";
    string ans1 = "";
    bool b = false;
    for (int i = 0; i<n; i++){
        string a; cin >> a;
        if (a == "0") b = true;
        else if (a == "1") continue;
        else if (a[0] == '1'){
            bool hola = true;
            for (int i = 1; i<sz(a); i++){
                if (a[i] != '0') {hola = false; break;}
            }
            if (hola) for (int i = 0; i<sz(a)-1; i++) ans += "0";
            else ans1 = a;
        }
        else ans1 = a;
    }
    if (ans1 == "") ans1 = "1";
    if (b) cout << 0 << ln;
    else  cout << ans1+ans << ln;

    return 0;
}