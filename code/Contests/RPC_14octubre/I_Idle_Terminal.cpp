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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    priority_queue<ll, vl, greater<ll>> pq;
    int n,k;cin>>n>>k;
    while(k--)pq.push(0);
    vi nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    ll tiempo=0,res=0;int act=0; 
    while(!pq.empty()){
        ll tmp=pq.top();pq.pop();
        if(act>=n){
            res=max(res, tmp-tiempo);
        }
        else if(tmp==0)pq.push(nums[act]);
        else{
            res=max(res, tmp-tiempo);
            pq.push(nums[act]+tmp);
        }tiempo=tmp;
        ++act;
    }cout<<res<<"\n";
    return 0;
}