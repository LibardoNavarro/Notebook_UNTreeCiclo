#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;
using namespace std::literals;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string name {"Libardo"}; //Inicialización de strings

    name = "Libardo Jose"; //Cambiar valor de un string

    //Ingresar strings con cin no es adecuado cuando se requiere strings con espacios
    //Para leer estos tipos de string se usa getline()
    string nombre {};
    cout << "Ingresa tu nombre: " << "\n";
    getline( cin >> ws, nombre);
    cout << nombre << "\n";

    //Tamaño de una string
    name.length();

    //Subcadena de una string
    cout << name.substr(1, 4);
}