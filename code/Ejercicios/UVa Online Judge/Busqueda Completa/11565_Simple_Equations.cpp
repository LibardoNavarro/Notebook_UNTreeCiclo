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

    int n; cin >> n;

    while(n--){
        int a, b, c; cin >> a >> b >> c;
        bool ans = true;
        for (int x = -100; x<=100; x++){
            for (int y = -100; y<=100; y++){
                for (int z = -100; z<=100; z++){
                    if (z!=x && z!=y && x!=y && (x+y+z==a) && (x*y*z==b) && (x*x + y*y + z*z == c)){
                        ans = false; cout << x << " " << y << " " << z << "\n"; break;
                    }
                }
                if (!ans) break;
            }
            if (!ans) break;
        }
        if (ans) cout << "No solution." << "\n";
    }
    
    return 0;
}