#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

vector<vi> adj(6);
vi dfs_num(6);
vi grados(6, 0);
vi orden;

map<int, char> letras = {
    {1, 'A'},
    {2, 'B'},
    {3, 'C'},
    {4, 'D'},
    {5, 'E'}
};
map<char, int> num = {
    {'A', 1},
    {'B', 2},
    {'C', 3},
    {'D', 4},
    {'E', 5}
};

void bfs(){
    queue<int> q;

    for (int i = 1; i<=5; i++){
        if (!grados[i]) q.push(i);
    }
    int nodo;

    while(!q.empty()){
        nodo = q.front(); q.pop();
        orden.push_back(nodo);
        for (int v : adj[nodo]){
            grados[v]--;
            if (grados[v] == 0) q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i<5; i++){
        string a; cin >> a;
        if (a[1] == '>'){
            adj[num[a[2]]].push_back(num[a[0]]);
            grados[num[a[0]]]++;
        }
        else{
            adj[num[a[0]]].push_back(num[a[2]]);
            grados[num[a[2]]]++;
        }
    }

    bfs();

    if (orden.size() == 5){
        for (int i : orden) cout << letras[i];
    }
    else{
        cout << "impossible";
    }
}