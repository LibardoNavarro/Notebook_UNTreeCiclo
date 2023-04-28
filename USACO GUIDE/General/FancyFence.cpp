#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    double n; cin >> n;
    for (int i = 0; i < n; i++){
        double a; cin >> a;
        double x = - (360.0 / (a - 180.0));
        if ( x == (int)x ){
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}