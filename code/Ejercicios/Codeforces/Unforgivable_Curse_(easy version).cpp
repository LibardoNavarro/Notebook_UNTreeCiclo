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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;
        string s, t; cin >> s >> t;
        if (s==t) cout << "YES\n";
        else {
            map<char, int> m;
            for (char c : s) m[c]++;
            for (char c : t) m[c]--;
            int ans = 0;
            for (auto p : m) {if (p.second >0) ans++;}
            if (ans!=0) {cout << "NO\n"; continue;}
            if (n>=6) {cout << "YES\n"; continue;}
            else if (n==5) cout << (s[2]==t[2]?"YES\n":"NO\n");
            else if(n==4) cout << ((s[2]==t[2] && s[1]==t[1])?"YES\n":"NO\n");
            else cout << "NO\n";
        }
    }
    
    return 0;
}