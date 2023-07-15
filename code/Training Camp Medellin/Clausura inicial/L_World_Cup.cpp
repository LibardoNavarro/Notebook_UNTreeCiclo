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

    int a, b, n; cin >> n >> a >> b;
    int f = log2(n);

    for (int i = 1; i<=f; i++){
        int c = pow(2, i);
        if ((a-1)/c == (b-1)/c){
            if (i == f){
                cout << "Final!" << "\n";
            }
            else{
                cout << i << "\n";
            }
            break;
        }
    }
    
    return 0;
}