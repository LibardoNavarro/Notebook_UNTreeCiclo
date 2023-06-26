#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int m) {
    if (n == m)
        return true;
    if (n > m) {
        if (n % 3 == 0 && (m == 2 * (n / 3) || m == n / 3))
            return true;
        else if (n % 3 == 0)
            return solve(n / 3, m) || solve(2 * (n / 3), m);
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        if (solve(n, m))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
