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

ll bs(ll n){
    ll izq = 0, der = 1e6, ans = 0;
    while(izq<=der){
        ll mid = (izq+der)>>1;
        if (mid*mid == n) return mid;
        else if(mid*mid>n) der = mid-1;
        else{
            izq = mid+1, ans = izq;
        }
    }
    return izq-1;
}

ll solve(ll n){
    ll raiz = bs(n);
    return raiz + (raiz-1) + ceil((double)(n-raiz*raiz)/raiz);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    cout << solve(n) << "\n";

    return 0;
}