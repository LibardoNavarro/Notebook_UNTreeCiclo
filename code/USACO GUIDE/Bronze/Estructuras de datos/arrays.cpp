#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declarar un array de enteros de tamaño 5
    array <int, 5> myArray;

    //Inicialización de arrays
    array <int, 4> arreglo = {1, 2, 3, 4};
    array <int, 4> arreglo1 {1, 2, 3, 4};
    array arreglo2 {1, 2, 3, 4, 5};

    array <int, 5> miArray;
    miArray = {1, 2}; //Los demás valores se harían cero

    //Tamaño de un array
    myArray.size();

    //Acceder a los elementos
    for (int element : myArray)
        cout << element << ' ';

    //Ordenar los arrays
    sort(myArray.begin(), myArray.end());

    //Ordenar los arrays descendentemente
    sort(myArray.rbegin(), myArray.rend());

    //Los arrays se pasan por referencia
    //void printLength(const std::array<double, 5>& myArray)

}