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

vi v;
string p;
int n;
int m;

bool solve(int a, string t){
    vector<bool> l(n);
    for (int i = 0; i<a; i++){
        l[v[i]] = true;
    }

    string s = "";

    for (int i = 0; i<n; i++){
        if (!l[i]) s += t[i];
    }

    int j = 0;

    for (int i = 0; i<sz(s); i++){
        if (s[i] == p[j]) j++;
        if (j == m) break;
    }
    if (j<m) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string t; cin >> t;
    cin >> p;
    n = sz(t);
    m = sz(p);
    v.resize(n);

    for (int i = 0; i<n; i++) {cin >> v[i]; v[i]--;}
    if (t == p){
        cout << 0 << "\n";
    }
    else{

    int izq = 0;
    int der = n-1;
    int ans = 0;
    while(izq<=der){
        int mid = (izq+der)/2;

        //000000000000011111111111111

        if (solve(mid, t)){
            ans = mid;
            izq = mid + 1;
        }
        else{
            der = mid-1;
        }
    }
    cout << ans << "\n";
    }
    
    return 0;
}