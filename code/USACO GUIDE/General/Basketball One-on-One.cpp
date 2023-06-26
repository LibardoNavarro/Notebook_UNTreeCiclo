#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    string game; cin >> game;
    int a = 0;
    int b = 0;
    for (int i = 0; i < game.length(); i += 2){
        if (game[i] == 'A'){
            a += game[i+1] - '0';
        }
        else if (game[i] == 'B'){
            b += game[i+1] - '0';
        }

        if (a >= 11 || b >= 11){
            if ( abs(a-b) > 1){
                if (a > b){
                    cout << 'A';
                }
                else{
                    cout << 'B';
                }
                break;
            }
        }
    }
}