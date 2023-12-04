#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define trace(x) cerr<<#x<<"="<<x<<'\n'
#define sz(arr) ((int) arr.size())
#define len(str) ((int) str.length())
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define PB push_back
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
// freopen("in.txt", "r", stdin);
int m;cin>>m;
vl meses(m);
ll unAno=0;
for(int i=0;i<m;++i){
  cin>>meses[i];
  unAno+=meses[i];
}
ll dia1,dia2,mes1,mes2,ano1,ano2;
cin>>dia1>>mes1>>ano1>>dia2>>mes2>>ano2;
ll res=0;
if(ano2-ano1>2){
  res+=(ano2-ano1-1)*unAno;
}
if(ano1==ano2){
  for(int i=mes1;i<mes2-1;++i){
    res+=meses[i];
  }
  if(mes1==mes2){
    res+=dia2-dia1;
  }else{
    res+=meses[mes1-1]-dia1;
    res+=dia2;
  }
}else{
  res+=meses[mes1-1]-dia1;
  for(int i=mes1;i<m;++i){
    res+=meses[i];
  }
  for(int i=0;i<mes2-1;++i){
    res+=meses[i];
  }
  res+=dia2;
}
cout<<res<<"\n";
return 0;
}