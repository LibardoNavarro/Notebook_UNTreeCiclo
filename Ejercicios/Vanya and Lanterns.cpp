#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    double long l; cin >> l;

    vector<double long> linternas(n);

    for (int i = 0; i<n ; i++){
        double long a; cin >> a;
        linternas[i] = a;
    }

    sort(linternas.begin(), linternas.end());

    double long maximo = 0.0;

    for (int i = 1; i<n; i++){

        double long distancia = (linternas[i] - linternas[i-1]);

        maximo = max(maximo, distancia);

    }

    double long z = max((linternas[0] - 0), (l - linternas[n-1]));

    cout << fixed << setprecision(9) << max(2*z, maximo) / 2.0;

}