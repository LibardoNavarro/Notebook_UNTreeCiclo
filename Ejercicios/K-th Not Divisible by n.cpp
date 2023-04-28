#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    for (int i = 0; i<t; i++){

        int n, k; cin >> n >> k;

        cout << k + ((k-1)/(n-1)) << "\n";

    }
    
}