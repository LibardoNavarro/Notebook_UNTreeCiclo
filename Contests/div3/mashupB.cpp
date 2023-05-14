#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
string letras = "abcdefghijklmnopqrstuvwxyz";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<string> palabras;
    set<char> distintas;
    map<string, int> veces;

    for (int i = 0; i<n; i++){
        string s; cin >> s;
        for (char c: s){
            distintas.insert(c);
        }
        if (distintas.size() <= 2){
            palabras.push_back(s);
        }
    }

    for (char letra : letras){
        string st(1, letra);
        for (string palabra : palabras){
            bool b = true;
            for (char c: palabra){
                if (c != letra){
                    b = false;
                    break;
                }
            }
            if (b){
                veces[st]++;
            }
        }
    }

    for (int i = 0; i<26; i++){
        char letra1 = letras[i];
        for (int j = i; j<26; j++){
            char letra2 = letras[j];
            if (letra1 == letra2) continue;
            for (string palabra : palabras){
            bool b = true;
            for (char c: palabra){
                if ((c != letra1) or (c != letra2)){
                    b = false;
                    break;
                }
            }
            if (b){
                string st1(1, letra1);
                string st2(1, letra2);
                st1 += st2;
                veces[st1]++;
            }
        }
    }
    ll max = 0;
    for (auto com : veces) {
        if (com.second > max){
            max = com.second;
        }
    }
    cout << max;
}
}