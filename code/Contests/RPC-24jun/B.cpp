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

int solve(int n, int l, int ans) {
    if (n == l)
        return ans;
    if (n > l) {
        if (n % 3 == 0 && (m == 2 * (n / 3) || m == n / 3))
            return true;
        else if (n % 3 == 0)
            return solve(n / 3, m) || solve(2 * (n / 3), m);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    
}