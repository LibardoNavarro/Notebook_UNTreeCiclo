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
int a;
int b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    set<int> s;
    for (int i = 0; i<q; i++){
        char c;
        cin >> c;
        if (c == '?'){
            int w, z;
            cin >> w >> z;
            int x = min(w, z);
            int y = max(w, z);  
            int a = *s.lower_bound(x);
            int b = *s.lower_bound(y);
            int c = *s.lower_bound(0);
            bool d = false;
            if (!(a >= x && a <= y)) d = true;
            
            if (!(((b >= y)) || (c<=x))) d = true;

            if (d) cout << "possible" << "\n";
            else cout << "impossible" << "\n";
        }
        else if (c == '-'){
            int x; cin >> x;
            s.insert(x);
        }
        else if (c == '+'){
            int x; cin >> x;
            s.erase(x);
        }

    }
}
