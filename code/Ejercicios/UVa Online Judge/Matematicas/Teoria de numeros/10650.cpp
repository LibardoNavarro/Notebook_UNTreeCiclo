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
vector<int> ans[165];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve(32000);
    int mx, a, b;
    while (true){
        int x, y; cin >> x >> y;
        if (x==0 && y==0) break;
        if (x > y) swap(x, y);
        int izq = upper_bound(p.begin(), p.end(), x) - p.begin() - bs[x];
        int der = lower_bound(p.begin(), p.end(), y) - p.begin() - !bs[y];
        a = 0;
        mx = -1;
        for (int i = 1; i <= 25; ++i) {
			for (int j = izq; j < der; ++j) {

				int cnt = 0, l = j, r;
				if (p[j] - p[j - 1] == i)
					continue;
				while (j + 1 <= der && (p[j + 1] - p[j]) == i)
					++cnt, ++j;
				if (cnt >= 2 && p[j + 1] - p[j] != i) {
					mx = max(mx, i);
					b = 0;
					r = j;
					ans[a].resize(r - l + 1);
					while (l <= r)
						ans[a][b++] = (p[r--]);
					a++;
				}
			}
		}

        sort(ans, ans + a);
		for (int i = 0; i < a; ++i){
            for (int j = ans[i].size() - 1; j >= 0; --j){
                if (!j) cout << ans[i][j] << "\n";
                else cout << ans[i][j] << " ";
            }
        }
    }
    
    return 0;
}