#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int dfs(int i, int j, vector<vector<char>>& mapa, char letra) {
    if (i >= 0 && i < sz(mapa) && j >= 0 && j < sz(mapa[0])) {
        if (mapa[i][j] == letra) {
            mapa[i][j] = '#';
            int n1 = dfs(i + 1, j, mapa, letra);
            int n2 = dfs(i - 1, j, mapa, letra);
            int n3 = dfs(i, j + 1, mapa, letra);
            int n4 = dfs(i, j - 1, mapa, letra);
            return n1 + n2 + n3 + n4 + 1;
        }
    }
    return 0;
}


int dfs2(int i, int j, vector<vi>& mapa, int numero) {
    if (i >= 0 && i < sz(mapa) && j >= 0 && j < sz(mapa[0])) {
        if (mapa[i][j] == numero) {
            mapa[i][j] = 0;
            int n1 = dfs2(i + 1, j, mapa, numero);
            int n2 = dfs2(i - 1, j, mapa, numero);
            int n3 = dfs2(i, j + 1, mapa, numero);
            int n4 = dfs2(i, j - 1, mapa, numero);
            return n1 + n2 + n3 + n4 + 1;
        }
    }
    return 0;
}

int componentes(vector<vector<char>>& mapa) {
    unordered_map<char, int> dic;
    for (int i = 0; i < mapa.size(); i++) {
        for (int j = 0; j < mapa[0].size(); j++) {
            if (mapa[i][j] != '#') {
                char guardar = mapa[i][j];
                int num = dfs(i, j, mapa, mapa[i][j]);
                if (num > 1) {
                    dic[guardar] = max(dic[guardar], num);
                }
            }
        }
    }
    int res=0;
    for (const auto& par : dic) {
        int r=par.second;
        res+=(r*(r-1))/2;
    }
    return res;
}

int componentes2(vector<vector<int>>& mapa) {
    unordered_map<int, int> dic;
    for (int i = 0; i < sz(mapa); i++) {
        for (int j = 0; j < sz(mapa[0]); j++) {
            if (mapa[i][j] != 0) {
                int guardar = mapa[i][j];
                int num = dfs2(i, j, mapa, mapa[i][j]);
                if (num > 1) {
                    dic[guardar] = max(dic[guardar], num);
                }
            }
        }
    }
    int res=0;
    for (const auto& par : dic) {
        int r=par.second;
        res+=(r*(r-1))/2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> letras;
    vector<vector<int>> numeros;
    for (int i = 0; i < n; i++) {
        vector<char> fila;
        vector<int> fila2;
        for (int j = 0; j < n*2; j++) {
            if (j%2==0){
                char c;
                cin >> c;
                fila.push_back(c);
            } else {
                int c;
                cin >> c;
                fila2.push_back(c);
            }
        }
        letras.push_back(fila);
        numeros.push_back(fila2);
    }
    int res1 = componentes(letras);
    int res2 = componentes2(numeros);
    cout << res1 << " " << res2 << "\n";
    return 0;
}
