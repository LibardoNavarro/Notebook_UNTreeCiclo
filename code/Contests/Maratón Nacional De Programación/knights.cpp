#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
const int INF=1e9;
const ll INFL=1e18;
const int MOD=1e9+7;
const double EPS=1e-9;
int dirx[4]={0,-1,1,0};
int diry[4]={-1,0,0,1};
int dr[]={1,-1,2,2,1,-1,-2,-2};
int dc[]={2,2,1,-1,-2,-2,-1,1};
const string ABC="abcdefghijklmnopqrstuvwxyz";
const char ln='\n';

int R,C;
int floodfill(vector<vi> &vis, int r, int c, int d1, int d2){
    queue<ii> q;
    q.push({r, c});
    vis[r][c] = 0;
    while (!q.empty()){
        ii nodo = q.front(); q.pop();
        r = nodo.first, c = nodo.second;
        if (r == d1 && c == d2) return vis[r][c];
        for (int i = 0; i<8; i++){
            if (r+dr[i]<0 || r+dr[i]>=R || c+dc[i]<0 || c+dc[i]>=C) continue;
            if (vis[r+dr[i]][c+dc[i]] == -1) {q.push({r+dr[i], c+dc[i]}); vis[r+dr[i]][c+dc[i]] = vis[r][c]+1;}
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true){
            int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
            if (n == 0 && a == 0 && b == 0 && c == 0 && d == 0) break;
            R = n, C=n;
            vector<vi> vis(n, vi(n, -1));
            int ans = floodfill(vis, a, b, c, d);
            if (ans%2 != 0 || ans == -1) cout << "*" << "\n";
            else cout << ceil(ans/2) << "\n";
    }

}
