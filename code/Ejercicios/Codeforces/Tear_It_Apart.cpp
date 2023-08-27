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
const string abc = "abcdefghijklmnopqrstuvwxyz";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--){
        string s; cin >> s;
        int ans = INF;
        int len = sz(s);
        for (char c : abc){
            int maxi = -INF;
            int a = 0;
            for (char l : s){
                if (l==c) {maxi = max(maxi, a); a = 0;}
                else a++;
            }
            if (a && a!=len) maxi = max(maxi, a);
            if (maxi!=-INF) ans = min(maxi, ans);
        }
        cout << ((ans!=0 && ans!=1)?(int)log2(ans)+1:ans) << "\n";
    }
    
    return 0;
}