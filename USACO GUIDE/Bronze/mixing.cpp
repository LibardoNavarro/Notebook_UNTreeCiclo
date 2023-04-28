#include <bits/stdc++.h>
using namespace std;
typedef long long double;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    freopen("mixmilk.in", "r", stdin);
    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;
    int e, f; cin >> e >> f;

    pair <int, int> cubo1 = {a, b};
    pair <int, int> cubo2 = {c, d};
    pair <int, int> cubo3 = {e, f};

    array<pair<int, int>, 3> cubos = {cubo1, cubo2, cubo3};

    for (int i = 0; i < 100; i++){
        int z = cubos[i % 3].second;
        if (cubos[i % 3].second + cubos[(i+1) % 3].second > cubos[(i+1) % 3].first){
            cubos[i % 3].second -= cubos[(i+1) % 3].first - cubos[(i+1) % 3].second;
            cubos[(i+1) % 3].second = cubos[(i+1) % 3].first;
        }
        else{
            cubos[(i+1) % 3].second += cubos[i % 3].second;
            cubos[i % 3].second = 0;
        }
    }
    freopen("mixmilk.out", "w", stdout);
    cout << cubos[0].second << "\n" << cubos[1].second << "\n" << cubos[2].second << "\n";

}