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
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t; cin >> t;

    for (int i = 0; i<t; i++){
        int y1; cin >> y1;
        int n; cin >> n;
        vi v(10000, 1);
        for (int i = 0; i<n; i++){
            int y; cin >> y;
            v[y] = 0;
        }
        vi p(10001, 0);
        int suma = 0;

        for (int i = 0; i<10000; i++){
            suma += v[i];
            p[i+1] = suma;
        }

        int y2; cin >> y2;
        cout << p[y2] - p[y1-1] << "\n";
    }
    
}