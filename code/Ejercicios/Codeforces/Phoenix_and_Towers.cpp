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
        int n, m, x; cin >> n >> m >> x;

        vi h(n);
        for (int i = 0; i<n; i++) cin >> h[i];
        map<int, queue<int>> a;
        for (int i = 0; i<n; i++){
            a[h[i]].push(i);
        }
        vi h1 = h;
        sort(h1.begin(), h1.end());
        vi towers(m, 0);
        map<int, int> indices;
        for (int i = 0; i<n; i++){
            int index = a[h1[i]].front(); a[h1[i]].pop();
            towers[i%m] += h1[i];
            indices[index] = i%m;
        }
        if (towers[m-1] - towers[0] <= x){
            cout << "YES" << "\n";
            for (int i = 0; i<n; i++){
                cout << indices[i] + 1 << " ";
            }
            cout << "\n";
        }
        else cout << "NO" << "\n";
    }
    
    return 0;
}