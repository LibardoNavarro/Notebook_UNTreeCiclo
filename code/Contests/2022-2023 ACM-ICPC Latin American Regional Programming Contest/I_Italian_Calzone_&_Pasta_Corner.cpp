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

int bfs(vector<vi>& adj, int x, int y, int r,int c){
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    visited[x][y]=true;
    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
    pq.push({adj[x][y], {x,y}});
    int count=1;
    while(!pq.empty()){
        auto act=pq.top();pq.pop();
        for(int i=0;i<4;i++){
            int x2=act.second.first+dirx[i];
            int y2=act.second.second+diry[i];
            if(x2>=0 && x2<r && y2>=0 && y2<c){
                if (adj[x2][y2] > act.first && visited[x2][y2]==false){
                    visited[x2][y2]=true;
                    pq.push({adj[x2][y2], {x2, y2}});
                    count++;
                }
            }
        }
    }
    return count;

}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
// cout << setprecision(20) << fixed;
int r,c;cin>>r>>c;
vector<vi> adj(r,vi(c));
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>adj[i][j];
    }
}
int maximo=0;
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        maximo=max(maximo,bfs(adj, i, j, r,c));
        // cout<<adj[i][j]<<" ";
    }
}cout<<maximo<<"\n";
return 0;
}