#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define trace(x) cerr<<#x<<"="<<x<<'\n'
#define sz(arr) ((int) arr.size())
#define all(x) x.begin(), x.end()
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
ll t,x,a,d,m,xi,ai,di;cin>>t;
string st;
while(t--){
  cin>>x>>a>>d>>m;
  vector<vl> misions1;
  vector<vl> misions2;
  set<vl> pos;bool pasa=false;
  for(int i=0;i<m;i++){
    cin>>st>>xi>>ai>>di;
    if(i<m/2)misions1.push_back({xi,ai,di});
    else misions2.push_back({xi,ai,di});
  }
//   ll mask= (1ll<<(m/2)+1);
  for (ll subset = 0; subset < (1<<misions1.size()); ++subset){
	  vl act={0,0,0};
    for (int i=0; i<m/2; i++){
      if (subset & (1<<i)){
          act[0]+=misions1[i][0];
          act[1]+=misions1[i][1];
          act[2]+=misions1[i][2];
      }
		}
    vl vecN = {x,a,d};
    if (act==vecN){
      pasa = true;
      break;
    }
		pos.insert(act);
	}
//   mask =(1ll<<(m-m/2+1));
//   cout<<mask<<"\n";
  for (ll subset = 0; subset < (1<<misions2.size()); ++subset){
    vl act={x,a,d};
    for (int i=0; i<m-m/2; i++){
      if (subset & (1<<i)){
          act[0]-=misions2[i][0];
          act[1]-=misions2[i][1];
          act[2]-=misions2[i][2];
      }
    }

    vl vecN = {0,0,0};
    if (act==vecN){
      pasa = true;
      break;
    }
    if (pos.count(act)){ 
		pasa=true;
		break;
	}
  }
  if(pasa)cout<<"POSSIBLE\n";
  else cout<<"IMPOSSIBLE\n";
}
return 0;
}