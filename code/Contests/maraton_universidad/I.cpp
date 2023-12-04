#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const double EPS  = 1e-9;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

void bfs(string inicial, unordered_map<string, ii> &padre){
    unordered_set<string> vis;
    
    vis.insert(inicial);
    queue<string> q;
    q.push(inicial);

    while (!q.empty()){
        string actual = q.front();
        q.pop();
        for (int i = 0; i<9; i++){
            if (((i+1) / 3 == i/3)){
                string temp = actual;
                swap(temp[i], temp[i+1]);
                if (!vis.count(temp)){
                    q.push(temp);
                    padre[temp] = {i, i+1};
                    vis.insert(temp);
                }
            }
            if (i + 3 < 9){
                string temp = actual;
                swap(temp[i], temp[i+3]);
                if (!vis.count(temp)) {
                    q.push(temp);
                    padre[temp] = {i, i+3};
                    vis.insert(temp);
                }
            }
        }
    }
}

void path(string inicial, string fin, int cont, unordered_map<string, ii> &padre){
    if (inicial == fin) {cout << cont << ln; return;}
    string temp = fin;
    int i = padre[temp].first, j = padre[temp].second;
    swap(temp[i], temp[j]);
    path(inicial, temp, cont + 1, padre);
    cout << i/3 + 1 << " " << i%3 + 1 << " " << j/3 + 1 << " " << j%3 + 1 << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    unordered_map<string, ii> padre;
    vector<string> inicial1(3);
    for (int i = 0; i<3; ++i) {
        string s = "";
        for (int j = 0; j<3; ++j){
            char c; cin >> c;
            s += c;
        }
        inicial1[i] = s;
    }

    string inicial = "";
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            inicial += inicial1[i][j];
        }
    }

    bfs(inicial, padre);

    int q; cin >> q;

    while (q--){
        vector<string> matrix(3);
        for (int i = 0; i<3; ++i) {
            string s = "";
            for (int j = 0; j<3; ++j){
                char c; cin >> c;
                s += c;
            }
            matrix[i] = s;
        }
        string hola = "";
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                hola += matrix[i][j];
            }
        }

        path(inicial, hola, 0, padre);
    }

    return 0;
}