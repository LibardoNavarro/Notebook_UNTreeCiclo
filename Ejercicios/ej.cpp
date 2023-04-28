#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    short t; cin >> t;

    while(t--){

        short n; cin >> n;
        vector<short> vec(n);
        for (short i = 0; i<n; i++){
            short a; cin >> a;
            vec[i] = a;
        }

        short suma = 0;
        vector<short> sumas;
        sumas.push_back(0);
        for (short i = 0; i<n; i++){
            suma += vec[i];
            sumas.push_back(suma);
        }

        vector<short> esta(n+1);

        for (short i = 0; i<n; i++){
            esta[vec[i]]++;
        }

        short z = 0;
        for (short i = 0; i<n; i++){
            int suma = 0;
            for (short j = i+1; j<n; j++){
                int y = (sumas[j+1] - sumas[i]) - 1;
                if (y >= 0 && y<=n-1){
                if (esta[y] != 0 && i != j){
                    z += esta[y];
                    esta[y] = 0;

                }
            }

            }

        }

        cout << z << "\n";

    }

}