#include <bits/stdc++.h>
using namespace std;

#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
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

const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n, q; cin >> n >> q;
    vi v(n);
    for (int i = 0; i<n; i++) cin >> v[i];

    sort(all(v));

    map<int, set<ii>> m;
    ii em = {0, 0};
    for (int i = 0; i<n; i++){
        for (int j = i+1; j<n; j++){
            m[v[i] + v[j]].insert({v[i], v[j]});
        }
    }

    for (int i = 0; i<q; i++){
        int k; cin >> k;
        if (!binary_search(all(v), k)) {cout << "NO\n"; continue;}
        bool anss = false;
        for (int j = 0; j<n; j++){
            int b = k-v[j];
            if (!m[b].empty()){
                for (ii p : m[b]){
                    if (v[j] != p.first && v[j] != p.second){
                        anss = true;
                        array<int, 3> ans = {v[j], p.first, p.second};
                        sort(all(ans));
                        cout << ans[0] << " " << ans[1] << " " << ans[2] << ln;
                        break;
                    }
                }
            }
            if (anss) break;
        }
        if (!anss) cout << "NO\n";
    }
    
    return 0;
}