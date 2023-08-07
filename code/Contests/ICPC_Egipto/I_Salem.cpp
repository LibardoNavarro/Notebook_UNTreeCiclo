#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const char ln='\n';
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n0;cin>>n0;
    while(n0--){
        ll n1;cin>>n1;
        vl vals(n1,0);
        for(int i=0;i<n1;i++)cin>>vals[i];

        ll maxi=0;
        for(int i=0;i<n1;i++){
            for(int e=0;e<n1;e++){
                bitset<30> bits(vals[i]^vals[e]);
                maxi = max(maxi,(ll)bits.count());
            }
        }
        cout<<maxi<<ln;
    }
        
}