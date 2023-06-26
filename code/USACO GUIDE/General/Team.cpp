#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a = 0;
    int n; cin >> n;
    for (int i = 0; i < n ; i++){
        int b = 0;
        int c = 0;
        for (int j = 0; j < 3; j++){
            cin >> c;
            if ( c == 1){
                b += 1;
            }
        }
        if (b >= 2){
            a++;
        }
    }
    cout << a;
}