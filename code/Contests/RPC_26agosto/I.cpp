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
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vi v(n);
    for (int i = 0; i<n; i++) cin >> v[i];
    int maxi = *max_element(v.begin(), v.end());
    set<int> estan(v.begin(), v.end());
    set<int> s;
    for (int i = 1; i<=maxi; i++){
        if (!estan.count(i)) s.insert(i);
    }
    int z = *s.rbegin();
    s.insert(maxi + 1);
    int q; cin >> q;
    for (int i = 0; i<q; i++){
        int a; cin >> a;
        int pos = *s.lower_bound(v[a-1]);
        if (pos == *s.rbegin()) s.insert(pos+1);
        s.erase(pos);
        s.insert(v[a-1]);
        v[a-1] = pos;
        cout << pos << "\n";
    }
}