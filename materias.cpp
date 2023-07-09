#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<vi> adj(72);
vi grado(72);
vii orden;
vi distancia(72);

void bfs(){
    queue<int> q;

    for (int i = 1; i<=71; i++){
        if (!grado[i]) {q.push(i); distancia[i] = 1;}
    }
    int nodo;

    while(!q.empty()){
        nodo = q.front(); q.pop();
        orden.push_back({distancia[nodo], nodo});
        for (int v : adj[nodo]){
            grado[v]--;
            if (grado[v] == 0) {q.push(v); distancia[v] = distancia[nodo] + 1;}
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, string> materias = {
        {1, "Geometria Vectorial"},
        {2, "Calculo Diferencial"},
        {3, "Calculo Integral"},
        {4, "Algebra Lineal"},
        {5, "Matematicas Discretas"},
        {6, "Estadistica 1"},
        {7, "Fisica Mecanica"},
        {8, "Ecuaciones Diferenciales"},
        {9, "Calculo en Varias Variables"},
        {10, "Matematicas Especiales"},
        {11, "Metodos Numericos"},
        {12, "Fundamentos de Matematicas"},
        {13, "Geometria Aplicada"},
        {14, "Estadistica 2"},
        {15, "Estadistica Descriptiva"},
        {16, "Estadistica 3"},
        {17, "Fisica de Electricidad y Magnetismo"},
        {18, "Fisica de Oscilaciones, Ondas y Optica"},
        {19, "Quimica General"},
        {20, "Laboratorio de Quimica General"},
        {21, "Biologia General"},
        {22, "Introduccion al Manejo de Datos Estadisticos"},
        {23, "Fundamentos de Programacion"},
        {24, "Programacion Orientada a Objetos"},
        {25, "Estructura de Datos"},
        {26, "Bases de Datos 1"},
        {27, "Teoria de Lenguajes de Programacion"},
        {28, "Introduccion a la Inteligencia Artificial"},
        {29, "Sistemas Operativos"},
        {30, "Redes y Telecomunicaciones I"},
        {31, "Fundamentos de Analítica"},
        {32, "Ingeniería de Software"},
        {33, "Ingeniería de Requisitos"},
        {34, "Calidad de Software"},
        {35, "Introducción a la Ingeniería de Sistemas e Informática"},
        {36, "Investigación de Operaciones I"},
        {37, "Introducción al Análisis de Decisiones"},
        {38, "Simulación de Sistemas"},
        {39, "Fundamentos de Sistemas de Información e Inteligencia de Negocios"},
        {40, "Técnicas de Aprendizaje Estadístico"},
        {41, "Sistema de Recuperación de Información de web"},
        {42, "Visión Artificial"},
        {43, "Redes Neuronales Artificiales y Algoritmos Bioinspirados"},
        {44, "Introducción a la Robótica"},
        {45, "Diseño y Construcción de Productos de Software"},
        {46, "Bases de Datos II"},
        {47, "Análisis y Diseño de Algoritmos"},
        {48, "Programación Matemática"},
        {49, "Sistemas Complejos"},
        {50, "Investigación de Operaciones II"},
        {51, "Dinámica de Sistemas"},
        {52, "Teoría de la Organización Industrial"},
        {53, "Gestión de Proyectos de Software"},
        {54, "Cátedra de Sistemas: una Visión Histórico-Cultural de la Computación"},
        {55, "Ciencias de la Computación y Aplicaciones Móviles"},
        {56, "Introducción a la Creación de Videojuegos"},
        {57, "Seguridad Web"},
        {58, "Fundamentos de Economía"},
        {59, "Teoría Administrativa y Organizacional"},
        {60, "Gestión del Talento Humano"},
        {61, "Fundamentos de Mercadeo"},
        {62, "Investigación de Mercados"},
        {63, "Redes Teleinformáticas I"},
        {64, "Redes Teleinformáticas II"},
        {65, "Redes Teleinformáticas III"},
        {66, "Programación para Ingeniería"},
        {67, "Servicios en la Nube"},
        {68, "Desarrollo Web"},
        {69, "Creación Multimedia"},
        {70, "Existo para acomodar Fundamentos"},
        {71, "Existo para acomodar TLP"}
    };
    
    while(true){
        int a, b; cin >> a >> b;
        if (a == 0 && b == 0){
            break;
        }
        adj[a].push_back(b);
        grado[b]++;
    }

    bfs();

    if (orden.size() == 71){
        for (ii i : orden) cout << i.first << " " << materias[i.second] << "\n";
    }
    else{
        cout << "Hay un prerrequisito mal puesto que forma un ciclo"; //No es un grafo aciclico dirigido (tiene un ciclo)
    }
    
}