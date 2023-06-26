#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int tractor = 0;
    int z = min(x, y);
    int w = max(x, y);
    tractor += abs(a - z);
    tractor += abs(b - w);
    if (tractor < b - a){
        cout << tractor;
    }
    else{
        cout << abs(b-a);
    }
}