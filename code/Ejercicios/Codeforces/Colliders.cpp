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

vl p;
bitset<10001001> bs;
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

vl factores(ll n){
    vl fact;
    for (ll i = 0; i<sz(p) && p[i]*p[i]<=n; i++){
        if (n % p[i] == 0) fact.push_back(p[i]);
        while(n % p[i] == 0){
            n /= p[i];
        }
    }
    if (n != 1) fact.push_back(n);
    return fact;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    int n, m; cin >> n >> m;
    sieve(n);
    map<int, pair<bool, set<ll>>> act;
    set<ll> estan;
    for (int i = 0; i<m; i++){
        char o; int a; cin >> o >> a;
        if (o=='+'){
            if (estan.count(a)){
                cout << "Already on\n";
            }
            else{
                ll ans = 0;
                vl facts = factores(a); 
                for (ll f : facts){
                    if (act[f].first) {ans = *act[f].second.begin(); break;}
                }
                if (!ans){
                    for (ll f : facts){
                        act[f].second.insert(a);
                        act[f].first = true;
                    }
                    estan.insert(a);
                    cout << "Success\n";
                }
                else{
                    cout << "Conflict with " << ans << ln;
                }
            }
        }
        else{
            if (!estan.count(a)){
                cout << "Already off\n";
            }
            else{
                vl facts = factores(a);
                for (ll f : facts){
                    if (*act[f].second.begin() == *act[f].second.rbegin()) act[f].first = false;
                    act[f].second.erase(a);
                }
                estan.erase(a);
                cout << "Success\n";
            }
        }
    }
    
    return 0;
}