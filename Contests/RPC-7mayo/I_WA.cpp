//Relleno por difusion-etiquetado/coloreado de componentes conexos
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF 1000000000;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<vi> grid;
vi colores;
int R, C, usados = 0;

void floodfill(int r, int c, int c1, int c2){
    int ans = 1;
    vii pos;
    for (int d = 0; d < 8; d++){
        if (r + dr[d] < 0 || r + dr[d] >= R || c + dc[d] < 0 || c + dc[d] >= C) continue;
        if (grid[r + dr[d]][c + dc[d]] == c1){
            ii a = {r + dr[d], c};
            pos.push_back(a);
            ans++;
        }
        if (ans == 3){
            for (auto i : pos){
                grid[i.first][i.second] = -1;
            }
            usados += 3;
            colores[c1] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    R = pow(2, n); C = R;
    int total = R*C;
    int maxcolor = (pow(4, n) - 1) / 3;
    grid = vector<vi>(R, vi(C));
    colores = vi(maxcolor+1, 0);

    for (int i = 0; i<R; i++){
        for (int j = 0; j<C; j++){
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i<R; i++){
        for (int j = 0; j<C; j++){
            if ((grid[i][j] != -1) && (colores[grid[i][j]] == 0)){
                floodfill(i, j, grid[i][j], -1);
            }
        }
    }
    bool b = true;

    for (int i = 1; i<=maxcolor; i++){
        if (!colores[i]){
            b = false;
            break;
        }
    }

    if (b && ((total - usados) == 1)){
        cout << 1 << "\n";
    }
    else{
        cout << 0 << "\n";
    }
    for (int i = 0; i<R; i++){
        for (int j = 0; j<C; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}