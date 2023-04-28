#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    freopen("shell.in", "r", stdin);
    int n; cin >> n;
    array<int, 3> adivinaciones = {0, 0, 0};

    vi pos = {0, 1, 2}; 

    for (int i = 0; i<n ; i++){
        int a, b, c ; cin >> a >> b >> c;
        a--; b--; c--;
        swap(pos[a], pos[b]);
        adivinaciones[pos[c]]++;
    }
    freopen("shell.out", "w", stdout);
    cout << max({adivinaciones[0], adivinaciones[1], adivinaciones[2]});
}