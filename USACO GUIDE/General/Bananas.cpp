#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double k, n, w;
    cin >> k >> n >> w;
    int dolares = k * (w * (w+1) / 2);
    if (dolares - n >= 0){
        cout << dolares - n;
    }
    else {
        cout << 0;
    }
    
}