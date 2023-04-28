#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double n; cin >> n;
    cout << n << " ";
    while (n != 1){
        if (n % 2 != 0){
            n = 3*n + 1;
        }
        else{
            n /= 2;
        }
        cout << n << " ";
    }
}