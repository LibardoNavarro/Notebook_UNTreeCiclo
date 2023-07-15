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

    int q; cin >> q;

    for (int i = 0; i<q; i++){
        int n; cin >> n;
        if (n == 1){
            cout << -1 << "\n";
        }
        else if (n == 6 || n == 9){
            cout << 1 << "\n";
        }
        else if ( n==2 || n==3 || n==5 || n==7 || n==11){
            cout << -1 << "\n";
        }
        else{
            if (n % 4 == 0 || n % 4 == 2){
                cout << (n/4)<< "\n";
            }
            else{
                cout << (n/4) - 1 << "\n";
            }
        }
    }
    
    return 0;
}