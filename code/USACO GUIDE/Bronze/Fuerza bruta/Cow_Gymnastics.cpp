#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n; cin >> k >> n;

    vector<vi> rounds(k);

    for (int i = 0; i<k; i++){
        vi l(n);
        for (int j = 0; j < n; j++){

            int a; cin >> a;
            l[j] = a;

        }
        rounds[i] = l;

    }
    int count = 0;
    for (int i = 1; i < n+1; i++){

        for (int j = 1; j < n+1; j++){
            bool b = true;
            for (int x = 0; x < k; x++){
                if (i == j){
                    b = false;
                    break;
                }
                vector<int>::iterator itr1 = find(rounds[x].begin(), rounds[x].end(), i);
                vector<int>::iterator itr2 = find(rounds[x].begin(), rounds[x].end(), j);
                int w = distance(rounds[x].begin(), itr1);
                int y = distance(rounds[x].begin(), itr2);


                if (w > y){
                    b = false;
                    break;
                }

            }
            if (b){
                count++;
            }
        }

    }
    cout << count << "\n";
    
}