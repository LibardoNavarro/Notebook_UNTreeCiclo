#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){

        int n; cin >> n;
        string s; cin >> s;

        int izq = 0;
        int der = n-1;

        int delizq = 0;
        int delder = 0;

        while (izq <= der){

            if (s[izq] != '>'){
                izq++;
                delizq++;
            }
            else{
                break;
            }

            if (s[der] != '<'){
                der--;
                delder++;
            }
            else{
                break;
            }

        }

        cout << min(delizq, delder) << "\n";
        

    }
    
}