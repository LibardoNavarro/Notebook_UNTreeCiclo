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

    string s, t; cin >> s >> t;

    int n = sz(s);
    map<char, char> m;
    vector<pair<char, char>> pares;

    for (int i = 0; i < n; i++) {
        char cs = s[i];
        char ct = t[i];

        if (m.count(cs)) {
            if (m[cs] != ct) {
                cout << "-1" << "\n";
                return 0;
            }
        } else {
            if (m.count(ct) && m[ct] != cs) {
                cout << "-1" << "\n";
                return 0;
            }

            m[cs] = ct;
            m[ct] = cs;
            if (cs == ct){
                continue;
            }
            else if (cs < ct){
                pares.push_back({cs, ct});
            }
            else{
                pares.push_back({ct, cs});
            }
        }
    }

    cout << pares.size() << "\n";
    for (auto par : pares) {
        cout << par.first << " " << par.second << "\n";
    }

    return 0;
}