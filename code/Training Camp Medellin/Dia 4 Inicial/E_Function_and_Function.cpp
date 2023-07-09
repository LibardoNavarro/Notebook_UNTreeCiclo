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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> f ={
        {0, 1},
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 1},
        {5, 0},
        {6, 1},
        {7, 0},
        {8, 2},
        {9, 1}
    };

    int t; cin >> t;

    while (t--){
        int x, k; cin >> x >> k;

        while (x>1 && k>0){
            int a = 0;
            int x1 = x;
            
            while(x1>0){
                a += f[x1 % 10];
                x1 /= 10;
            }
            k--;
            x = a;
        }

        if (k>0){
            if (k % 2 == 0) cout << x << "\n";
            else {
                if (x == 1) cout << 0 << "\n";
                else cout << 1 << "\n";
            }
        }
        else{
            cout << x << "\n";
        }
    }
    
}