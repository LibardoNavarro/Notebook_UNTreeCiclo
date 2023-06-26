#include <bits/stdc++.h>
using namespace std;

int main() {

    //Las inserciones, eliminaciones y búsquedas son todas O(n)
    map<int, int> m;
    m[1] = 5;                    // [(1, 5)]
    m[3] = 14;                   // [(1, 5); (3, 14)]
    m[2] = 7;                    // [(1, 5); (2, 7); (3, 14)]
    m[0] = -1;                   // [(0, -1); (1, 5); (2, 7); (3, 14)]
    m.erase(2);                  // [(0, -1); (1, 5); (3, 14)]
    cout << m[1] << endl;        // 5
    cout << m.count(7) << endl;  // 0
    cout << m.count(1) << endl;  // 1
    cout << m[2] << endl;        // 0

    map<int, int> m;
    m[3] = 5; // [(3, 5)]
    m[11] = 4; // [(3, 5); (11, 4)]
    m[10] = 491; // [(3, 5); (10, 491); (11, 4)]
    cout << m.lower_bound(10)->first << " " << m.lower_bound(10)->second << '\n'; // 10 491
    cout << m.upper_bound(10)->first << " " << m.upper_bound(10)->second << '\n'; // 11 4
    m.erase(11); // [(3, 5); (10, 491)]

    //Recorrer un map
    for (auto x : m) { cout << x.first << " " << x.second << endl; }

    /*
    En m[key], si key no está presente en el mapa, el valor asociado key se 
    construye utilizando el constructor predeterminado del tipo de valor. 
    Por ejemplo, si el tipo de valor es int, al llamar m[key] a una clave que 
    no está dentro del mapa se establece el valor asociado con esa clave en 0. 
    Como otro ejemplo, si el tipo de valor es string, la llamada m[key] de una 
    clave que no está dentro del mapa establece el valor asociado con esa clave 
    en la cadena vacía.
    */
}