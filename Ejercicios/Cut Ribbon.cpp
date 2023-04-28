#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double n, a, b, c;
    cin >> n >> a >> b >> c;
    int max = 0;
    for (double i = n; i>= 0; i--){
        for (double j = n; j>= 0; j--){
            double z = (n-a*i-b*j) / c;
            if (z == (int) z && i + j + z > max && z >= 0){
                max = i + j + z;
            }
        }
    }
    cout << max;
}