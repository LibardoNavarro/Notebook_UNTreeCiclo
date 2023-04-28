#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    int e = min(a, c);
    int f = max(b , d);
    cout << f - e;

}