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

pair<bool, vl> dfs(ll v, int n, set<ll> s, vl ans, int a){
    ans.push_back(v);
    s.erase(v);
    a++;
    if (a == n){
        return {true, ans};
    }
    if (s.count(v*2)){
        pair<bool, vl> anss = dfs(v*2, n, s, ans, a); 
        if (anss.first){
            return anss;
        }
    }
    if (v % 3 == 0 && s.count(v/3)){
        pair<bool, vl> anss = dfs(v/3, n, s, ans, a); 
        if (anss.first){
            return anss;
        }
    }
    return {false, ans};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    set<ll> s;
    for (int i = 0; i<n; i++){
        ll a; cin >> a;
        s.insert(a);
    }

    for (ll v : s){
        vl ans;
        pair<bool, vl> anss = dfs(v, n, s, ans, 0);
        if (anss.first){
            for (int i = 0; i<n; i++){
                cout << anss.second[i] << " ";
            }
        }
    }
    
    return 0;
}