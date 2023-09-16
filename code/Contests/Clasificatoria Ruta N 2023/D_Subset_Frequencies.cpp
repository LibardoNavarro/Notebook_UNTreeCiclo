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
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool fsort(ii a,ii b){
    if (a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vi v(n);
    for (int i = 0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vii ans;
    for (int i = 0; i<k; i++){
        int q; cin >> q;
        int hola = 0;
        for (int j = 0; j<n; j++){
            if (2*v[j]>=q) break;
            if (binary_search(v.begin(), v.end(), q-v[j])) hola++;
        }
        ans.push_back({hola, q});
    }
    sort(ans.begin(), ans.end(), fsort);
    for(auto pval:ans){
        cout<<pval.second<<" "<<pval.first<<"\n";
    }
}