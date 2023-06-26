#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> multiplicar_matriz(vector<vector<ll>> matriz, vector<vector<ll>> matriz2,ll n){
    
    vector<vector<ll>> matrizp;

    for (ll i = 0; i<n; i++){
        vector<ll> v(n);
        matrizp.push_back(v);
    }
    for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                for(ll k=0;k<n;k++){
                    matrizp[i][j] = (matrizp[i][j] + matriz[i][k]*matriz2[k][j]) % 1000000007;
                }
            }
        }
    return matrizp;  
}

vector<vector<ll>> moduloMatriz(vector<vector<ll>> matriz, ll n, ll m){
    
    for (ll i=0;i<n;i++){
        for (ll e = 0;e<n;e++){
            matriz[i][e] = matriz[i][e] % m;
        }
    }

    return matriz;
}

vector<vector<ll>> identidad(ll n){
   vector<vector<ll>> identidad;
   for (ll i = 0; i<n; i++){
        vector<ll> v(n);
        identidad.push_back(v);
    }
    for (ll i=0;i<n;i++){
        for (ll e = 0;e<n;e++){
            if (e == i){
            identidad[i][e] = 1;

            }else{
            identidad[i][e] = 0;
            }
        }
    }
    return identidad;
}

vector<vector<ll>> exponenciacion_binaria(vector<vector<ll>> matriz, ll exponente, ll modulo, ll n){
    
    vector<vector<ll>> res = identidad(n);

    while (exponente > 0){
        if (exponente % 2 == 1){
            res = multiplicar_matriz(moduloMatriz(res, n, modulo), moduloMatriz(matriz, n, modulo), n);
        }
        matriz = multiplicar_matriz(moduloMatriz(matriz, n, modulo), moduloMatriz(matriz, n, modulo), n);
        exponente /= 2;
    }

    return moduloMatriz(res, n, modulo);

}

int main(){
    ll n, m, k; cin >> n >> m >> k;

    vector<vector<ll>> matriz;

    for (ll i = 0; i<n; i++){
        vector<ll> v(n);
        matriz.push_back(v);
    }

    for (ll i = 0; i<m; i++){
        ll a, b; cin >> a >> b;
        matriz[--a][--b] = 1;
        matriz[b][a] = 1;
    }

    matriz = exponenciacion_binaria(matriz, k, 1000000007, n);
    
    ll suma = 0;

    for (ll i=0;i<n;i++){
        suma = (suma + matriz[0][i]) % 1000000007;
    }

    cout << suma % 1000000007;

    return 0;
}