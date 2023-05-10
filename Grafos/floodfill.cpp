//Relleno por difusion-etiquetado/coloreado de componentes conexos
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF 1000000000;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};     //Truco para explorar rejilla 2d
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};     // vecinos S,SE,E,NE,N,NO,O,SO

vector<string> grid; 

int R, C, ans;

int floodfill(int r, int c, char c1, char c2){          //Devuelve tamaño de CC
    if (r < 0 || r >= R || c< 0 || c >= C) return 0;    //fuera de la rejilla
    if (grid[r][c] != c1) return 0;                     //No tiene color c1
    int ans = 1;                 //suma 1 a ans porque el vertice (r, c) tiene color c1
    grid[r][c] = c2;             //Colorea el vertice (r, c) a c2 para evitar ciclos
    for (int d = 0; d < 8; d++){
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    }
    return ans;         //El codigo es limpio porque usamos dr[] y dc[]
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R; cin >> C;
    cout << floodfill(2, 1, 'W', '.');
}