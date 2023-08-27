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

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        vi a(n);
        priority_queue<ii> pq;
        for (int i = 0; i<n; i++) {cin >> a[i]; pq.push({a[i], i});}
        ll ans = 0;
        vii pares;
        while (true){
            ii u = pq.top(); pq.pop();
            if (u.first > a[u.second]) continue;
            ii v = pq.top(); pq.pop();
            if (v.first > a[v.second]) {pq.push(u) ;continue;}
            if (v.first == 0) break;
            a[u.second]--, a[v.second]--;
            pq.push({a[u.second], u.second});
            pq.push({a[v.second], v.second});
            pares.push_back({u.second, v.second});
            ans++;
        }
        cout << ans << "\n";
        for (ii p : pares) cout << p.first+1 << " " << p.second+1 << "\n";
    }
    
    return 0;
}