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

ll ans;
int n, k;

void solve(string s, int t){
    if (t == n){
        int ceros = 0;
        int unos = 0;
        for (char d : s){
            if (d == '1'){
                ceros = 0;
                unos++;
                if (unos > k) return;
            }
            if (d == '0'){
                unos = 0;
                ceros++;
                if (ceros > k) return;
            }
        }
        ans++;
        return;
    }
    solve(s + "1", t+1);
    solve(s + "0", t+1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    solve("", 0);

    cout << ans << "\n";
    
}