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

vl p;
bitset<10000010> bs;
void sieve(ll n){
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i<=n; i++){
        if (bs[i]){
            for (ll j=i*i; j<=n; j+=i) bs[j] = 0;
            p.push_back(i);
        }
    }
}

ll numPF(ll N) {
    ll num = 0;
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i)
        while (N%p[i] == 0) {
            N /= p[i];
            num++;
        }
    return num + (N != 1);
}
vl pf(2000000);
bool cmp(ll a, ll b){
    if (a == 1) return true;
    else if (b == 1) return false;
    else{
        ll c = pf[a-1], d = pf[b-1];
        if (c != d) return c < d;
        else return a < b;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve(1e7);
    vl v(2000000);
    pf.clear();
    for (ll i = 0; i<2000000; i++){
        v[i] = i+1;
        pf[i] = numPF(i+1);
    }
    
    sort(v.begin(), v.end(), cmp);
    ll a = 0;
    while(true){
        a++;
        ll n; cin >> n;
        if (!n) break;
        cout << "Case " << a << ": " << v[n-1] << "\n";
        
    }
    
    return 0;
}