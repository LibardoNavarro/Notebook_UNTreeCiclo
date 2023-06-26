#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;

    vi x(n);
    vi y(n);

    for (int i = 0; i <n; i++){

        int a; cin >> a;
        x[i] = a;

    }
    for (int i = 0; i <n; i++){

        int b; cin >> b;
        y[i] = b;

    }
    int mayor = 0;

    for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){
            int distancia = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
            mayor = max(distancia, mayor);
        }

    }
    cout << mayor << "\n";
}