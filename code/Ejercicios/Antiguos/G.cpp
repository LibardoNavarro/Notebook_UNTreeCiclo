#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string bal;
    cin >> bal;

    vector<int> l = {0};
    int x = 0;
    for (char c : bal) {
        if (c == 'X') {
            x++;
            l.push_back(x);
        } else {
            l.push_back(x);
        }
    }

    int subsecuencias = 0;
    for (int i = 3; i <= sqrt(n); i++) {
        int xesperadas = 4*i - 4;
        int oesperadas = pow(i-2, 2);
        for (int j = 0; j <= n - i*i; j++) {
            int xs = l[j+i*i] - l[j];
            int os = i*i - xs;
            if (xs == xesperadas && os == oesperadas) {
                subsecuencias++;
            }
        }
    }

    cout << subsecuencias << "\n";
}
