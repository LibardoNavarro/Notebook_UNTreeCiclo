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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;

    while (q--){
        string s, t; cin >> s >> t;
        int ls = sz(s), lt= sz(t);
        int l = lcm(ls, lt);
        string ans1 = "", ans2="";
        for (int i = 0; i<l/ls; i++) ans1 += s;
        for (int i = 0; i<l/lt; i++) ans2 += t;
        if (ans1 == ans2) cout << ans1 << "\n";
        else cout << -1 << "\n";
    }
    
    return 0;
}