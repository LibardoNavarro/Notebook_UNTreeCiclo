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

#include <iostream>
#include <vector>
#define ll long long
#define vl vector<ll>
#define ln "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi v(n);
    for (int i = 0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i<q; i++){
        int o; cin >> o;
        if (o==1){
            int k; cin >> k;
            int index = lower_bound(v.begin(), v.end(), k) - v.begin();
            if (v[index] != k){
                if (k>v.back()) v.push_back(k);
                else {v[index] = k;}
            }
        }
        else{
            int a, b; cin >> a >> b;
            int indexA = lower_bound(v.begin(), v.end(), a) - v.begin();
            int indexB = upper_bound(v.begin(), v.end(), b) - v.begin();
            cout << indexB - indexA << "\n";
        }
    }
}