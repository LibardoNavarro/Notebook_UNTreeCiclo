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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vl v(n);
    map<ll, pair<ll,ii>> m;
    for (int i = 0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    set<int> s;

    for (int i = 1; i<n; i++){
        ll dif = v[i] - v[i-1];
        m[dif] = {m[dif].first+1, {v[i], v[i-1]}};
        s.insert(dif);
    }

    set<int> s1;

    for (int i = 0; i<n; i++){
        s1.insert(v[i]);
    }

    bool b = false;
    if (s1.size() != n){
        b = true;
    }

    if (n == 1){
        cout << -1 << "\n";
    }

    else if (s.size() > 2) cout << 0 << "\n";

    // else if()
    else if (s.size() == 1){
        
        int a = 2;

        if ((v[0] + v[1]) % 2 == 0 && n == 2){
            a++; 
        }

        vl vec;

        for (int i : s){
            vec.push_back(i);
        }

        if (v[0] - vec[0] == v[n-1] + vec[0]){
            cout << 1 << "\n";
            cout << v[0] - vec[0] << "\n";
        }
        else{

            cout << a << "\n";

            cout << v[0] - vec[0] << " ";

            if ((v[0] + v[1]) % 2 == 0 && n == 2){
                cout << (v[0] + v[1]) / 2 << " "; 
            }

            cout << v[n-1] + vec[0] << "\n";
        }
    } 
    else{
        vl vec;

        for (int i : s){
            vec.push_back(i);
        }

        if (vec[0] == 0 || vec[1] == 0 || min(m[vec[0]].first, m[vec[1]].first) >1 || max(vec[0], vec[1]) != 2 * min(vec[0], vec[1]) ){
            cout << 0 << "\n";
        }
        else{


            if (vec[0] > vec[1]){
                if (m[vec[0]].second.second + vec[1] != m[vec[0]].second.first - vec[1] || m[vec[0]].first > m[vec[1]].first){
                    cout << 0 << "\n";
                }
                else{
                    cout << 1 << "\n";
                    cout << m[vec[0]].second.second + vec[1] << "\n";
                }
            }
            else{
                if (m[vec[1]].second.first - vec[0] != m[vec[1]].second.second + vec[0] || m[vec[1]].first > m[vec[0]].first){
                    cout << 0 << "\n";
                }
                else{
                    cout << 1 << "\n";
                    cout << m[vec[1]].second.first - vec[0] << "\n";
                }
            }
        }
    }
}