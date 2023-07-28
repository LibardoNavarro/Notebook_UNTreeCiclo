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

vl p;
bitset<10000010> bs;
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

    sieve(1e6);

    int n, m; cin >> n >> m;

    vector<vi> matrix(n, vi(m));

    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++) cin >> matrix[i][j];
    }
    int ans = INF;
    for (int i = 0; i<n; i++){
        int pasos = 0;
        for (int j = 0; j<m; j++){
            int index = lower_bound(p.begin(), p.end(), matrix[i][j]) - p.begin();
            pasos += p[index] - matrix[i][j];
        }
        ans = min(pasos, ans);
    }

    for (int i = 0; i<m; i++){
        int pasos = 0;
        for (int j = 0; j<n; j++){
            int index = lower_bound(p.begin(), p.end(), matrix[j][i]) - p.begin();
            pasos += p[index] - matrix[j][i];
        }
        ans = min(pasos, ans);
    }
    cout << ans << "\n";
    
    return 0;
}