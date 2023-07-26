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

bool cmp(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        vector<pair<ll, ll>> lamps(n);
        map<ll, ll> m;
        for (int i = 0; i<n; i++){
            ll a, b; cin >> a >> b;
            lamps[i] = pair<ll, ll>(a, b);
        }
        sort(lamps.begin(), lamps.end(), cmp);
        int ult=-1;
        int x=0;
        ll sum=0;

        for(ii i:lamps){
            if (i.first==ult) x++;
            else{
                x=1;
                ult=i.first;
            }
            if(x<=i.first) sum+=i.second;
        }

        cout << sum << "\n";
    }
    
    return 0;
}