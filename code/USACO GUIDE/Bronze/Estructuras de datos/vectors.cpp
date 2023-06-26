#include <bits/stdc++.h>
using namespace std;
/*
Soportan todos los métodos de los arrays
Se pueden redimensionar
Agregar y eliminar elementos al final tiene complejidad O(1),
Hacerlo en mitad del vector tiene complejidad O(n)
*/
int main() {
    //Declaración de un vector
    vector<int> v;

    //Agregar un elemento a un vector
    v.push_back(17);
    v.push_back(18);
    v.push_back(19);

    //Cambiar un elemento de un indice
    v[1] = 16;

    //Remover un elemento de un indice
    v.erase(v.begin() + 1);

    //Remover el último elemento
    v.erase(v.end() -1);
    v.pop_back();

    v.push_back(4);
    v.push_back(4);
    v.push_back(9);

    //Remover los tres primeros elementos
    v.erase(v.begin(), v.begin() + 3);

    //Obtener el ultimo elemento de un vector
    v.back();

    //Otra forma de inicializar vectores
    // size 10, initial value 0
    vector<int> v(10);

    // size 10, initial value 5
    vector<int> v(10, 5);

}