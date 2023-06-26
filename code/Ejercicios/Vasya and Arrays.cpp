#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = x;
    }

    int m; cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        b[i] = x;
    }

    vector<int> sumA;
    int suma = 0;
    for (int i = 0; i < n; i++){
        suma += a[i];
        sumA.push_back(suma);
    }

    vector<int> sumB;
    suma = 0;
    for (int i = 0; i < m; i++){
        suma += b[i];
        sumB.push_back(suma);
    }
    
    if (sumA[n-1] != sumB[m-1]){
        cout << -1 << "\n";
    }

}