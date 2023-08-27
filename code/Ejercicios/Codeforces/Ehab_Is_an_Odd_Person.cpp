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

    int n; cin >> n;
    vi v(n);
    int imp=0, pa=0;
    for (int i = 0; i<n; i++) {cin >> v[i]; v[i] % 2 == 0? imp++ : pa++;}
    if (imp == n || pa==n) for (int i = 0; i<n; i++) cout << v[i] << " ";
    else{
        sort(v.begin(), v.end());
        for (int i = 0; i<n; i++) cout << v[i] << " ";
    }

    return 0;
}