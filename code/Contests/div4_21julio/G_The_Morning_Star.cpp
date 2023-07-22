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

pair<int, ii> puntosALineas(ii p1,ii p2){
    pair<int, ii> l;
    if (fabs(p1.first-p2.first)<EPS){
        l.first=1.0; l.second.first=0.0; l.second.second=-p1.first;
    }else{
        l.first= -double(p1.second-p2.second)/(p1.first-p2.first);
        l.second.first= 1.0;
        l.second.second= -double(l.first*p1.first)-p1.second;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        map<pair<int, ii>, ll> m;
        for (int i = 0; i<n; i++){
            int x, y; cin >> x >> y;
            ii p = {x, y};
            ii p1 = {x, y+1};
            ii p2 = {x+1, y};
            ii p3 = {x-1, y+1};
            ii p4 = {x+1, y+1};
            m[puntosALineas(p, p1)]++;
            m[puntosALineas(p, p2)]++;
            m[puntosALineas(p, p3)]++;
            m[puntosALineas(p, p4)]++;
        }
        ll sum = 0;
        for (auto l : m){
            sum += l.second * (l.second-1);
        }
        cout << sum << "\n";
    }
    
    return 0;
}