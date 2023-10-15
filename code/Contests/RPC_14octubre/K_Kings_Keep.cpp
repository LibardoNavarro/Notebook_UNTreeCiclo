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

// Punto flotante
struct point{
    double x,y;
    point(){}
    point(double _x,double _y): x(_x),y(_y){}
    bool operator == (point other) const{
        return (fabs(x-other.x)<EPS) && (fabs(y-other.y)<EPS);
    };
};

// Distancia entre dos puntos
double dist(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    int n;cin>>n;
    vector<point> p(n);
    for(int i=0;i<n;++i){
        int x,y;cin>>x>>y;
        point po(x,y);
        p[i]=po;
    }
    double res=INFL;
    for(int i=0;i<n;++i){
        double dis = 0;
        for(int j=0;j<n;++j){
            if(j==i)continue;
            dis += dist(p[i], p[j]);
        }
        res = min(res, dis);
    }

    cout << res / (n-1) << ln;
    return 0;
}