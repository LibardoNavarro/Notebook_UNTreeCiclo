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
        string l, r; cin >> l >> r;
        int l1 = sz(l);
        int l2 = sz(r);

        if (l1 < l2) {
            l = string(l2 - l1, '0') + l;
        }
        else if ((l1 > l2)){
            r = string(l1 - l2, '0') + r;
        }
        ll sum = 0;
        bool b = true;
        for (int i = 0; i<max(l1, l2); i++){
            if (b){
                if (l[i] != r[i]) b = false;
                sum += abs(l[i] - r[i]);
            }
            else{
                sum += 9;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}