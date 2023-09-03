#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF=1e9;
const ll INFL=1e18;
const int MOD=1e9+7;
const double EPS=1e-9;
int dirx[4]={0,-1,1,0};
int diry[4]={-1,0,0,1};
int dr[]={1,1,0,-1,-1,-1,0,1};
int dc[]={0,1,1,1,0,-1,-1,-1};
const string ABC="abcdefghijklmnopqrstuvwxyz";
const char ln='\n';

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll nums[10]= {3, 20, 119, 696, 4059, 23660, 137903, 803760, 4684659, 27304196};
    while (true){
        ll a, b; cin >> a >> b;
        if (a == 0 && b == 0) break;
        ll res = 0;
        for (int i=0;i<10;i++)if(nums[i]<=b && nums[i]>=a)res++;
        cout << res << ln;
    }
    return 0;

}
