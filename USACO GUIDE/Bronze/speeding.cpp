#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    
    int n, m ; cin >> n >> m;

    vi veln;

    int z = 0;
    for (int i = 0; i < n; i++){

        int a, b; cin >> a >> b;
        for (int j = 0; j < a; j++){
            veln.push_back(b);
        }

    }
    int y = 0;
    int max = 0;
    for (int i = 0; i < m; i++){

        int a, b; cin >> a >> b;
        for (int j = y; j < y + a; j++){
            if ((veln[j] - b) > max){

                max = (veln[j] - b);

            }
        }
        y += a;

    }

    cout << max << "\n";



}