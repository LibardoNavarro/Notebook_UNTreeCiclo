#include <bits/stdc++.h>
using namespace std;

#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;
int dirx[4] = {0, -1, 1, 0};
int diry[4] = {-1, 0, 0, 1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

pair<double, pair<double, double>> puntosALineas(pair<double, double> p1,pair<double, double> p2){
    pair<double, pair<double, double>> l;
    if (fabs(p1.first-p2.first)<EPS){
        l.first=1.0; l.second.first=0.0; l.second.second=-p1.first;
    }else{
        l.first= -double(p1.second-p2.second)/(p1.first-p2.first);
        l.second.first= 1.0;
        l.second.second= -double(l.first*p1.first)-p1.second;
    }
    return l;
}

int plano(pair<double, double> p){
  if (p.first >0 && p.second >0) return 1;
  else if (p.first >0 && p.second < 0) return 4;
  else if (p.first <0 && p.second < 0) return 3;
  else if (p.first <0 && p.second > 0) return 2;
  else if (p.first == 0 && p.second > 0) return 5;
  else if (p.first == 0 && p.second < 0) return 6;
  else if (p.second == 0 && p.first > 0) return 7;
  else return 8;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, k = 0;
    while (cin >> n >> k, n != 0 && k !=0){
      set<pair<int,pair<double, pair<double, double>>>> lineas;
      for (int i = 0; i<n; i++){
        double a, b; cin >> a >> b;
        if (a == 0 && b == 0) continue;
        pair<double, double> p = {a, b};
        auto linea = puntosALineas(p, {0.0, 0.0});
        lineas.insert({plano(p), linea});
      }
      cout << (sz(lineas)<=k?"ATTACK":"WAIT") << "\n";
      n = 0, k = 0;
    }    
    return 0;
}