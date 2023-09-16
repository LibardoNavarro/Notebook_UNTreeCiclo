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

    int n; cin >> n;

    if (n==1) cout << 1 << ln << 1 << ln;
    else if (n==2) cout << 1 << ln << 1 << " " << 1 << ln;
    else{
        cout << 2 << ln;
        vi prime(n+2, 1);
        for (ll i = 2; i<=n+1; i++){
            if (prime[i] == 1){
                for (ll j=i*i; j<=n+1; j+=i) prime[j] = 2;
            }
        }
        for (int i = 2; i<=n+1; i++){
            cout << prime[i] << " ";
        }
    }
    
    return 0;
}