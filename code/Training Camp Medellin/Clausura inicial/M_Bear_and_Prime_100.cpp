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

    vi l = {4, 9, 25, 49};
    vi p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    bool b = false;
    for (int i = 0; i<4; i++){
        cout << l[i] << endl;
        fflush(stdout);
        string s; cin >> s;
        if (s == "yes"){
            cout << "composite" << endl;
            fflush(stdout);
            b = true;
            break;
        }
    }
    if (!b){
        int c = 0;
        for (int n : p){
            cout << n << endl;
            fflush(stdout);
            string s; cin >> s;
            if (s == "yes"){
                c++;
            }
            if (c == 2){
                cout << "composite" << endl;
                fflush(stdout);
                b = true;
                break;
            }
        }
    }
    if (!b){
        cout << "prime" << endl;
        fflush(stdout);
    }
    
    return 0;
}