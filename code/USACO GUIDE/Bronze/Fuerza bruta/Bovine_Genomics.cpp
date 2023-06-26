#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; cin >> n >> m;

    vi A1(m);
    vi C1(m);
    vi G1(m);
    vi T1(m);

    for (int i = 0; i<n; i++){
        string s; cin >> s;
        for (int j = 0; j<m; j++){

            if (s[j] == 'A'){
                A1[j]++;
            }
            else if (s[j] == 'C'){
                C1[j]++;
            }
            else if (s[j] == 'G'){
                G1[j]++;
            }
            else if (s[j] == 'T'){
                T1[j]++;
            }

        }

    }

    vi A2(m);
    vi C2(m);
    vi G2(m);
    vi T2(m);

    for (int i = 0; i<n; i++){
        string a; cin >> a;
        for (int j = 0; j<m; j++){


            if (a[j] == 'A'){
                A2[j]++;
            }
            else if (a[j] == 'C'){
                C2[j]++;
            }
            else if (a[j] == 'G'){
                G2[j]++;
            }
            else if (a[j] == 'T'){
                T2[j]++;
            }

        }

    }

    int diferentes = 0;

    for (int i = 0; i<m; i++){

        if ((A1[i] == 0 and A2[i] != 0) or (A1[i] != 0 and A2[i] == 0)){
            diferentes++;
        }
        else if ((C1[i] = 0 and C2[i] != 0) or (C1[i] != 0 and C2[i] == 0)){
            diferentes++;
        }
        else if ((G1[i] == 0 and G2[i] != 0) or (G1[i] != 0 and G2[i] == 0)){
            diferentes++;
        }
        else if ((T1[i] == 0 and T2[i] != 0) or (T1[i] != 0 and T2[i] == 0)){
            diferentes++;
        }

    }

    cout << diferentes << "\n";

}