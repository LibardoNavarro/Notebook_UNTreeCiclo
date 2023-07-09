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
    ll n, q;cin >> n >> q;
    ll noti = 0;
    queue<pair<ll, ll>> notifications;
    vector<queue<ll>> aplications(n + 1);
    vector<bool> visto(q, false);
    ll eventos = 1;
    for (ll i = 0; i < q; i++) {
        ll typ, x;cin >> typ >> x;
        if (typ == 1) {
            notifications.push(make_pair(eventos, x));
            aplications[x].push(eventos);
            eventos++;
            noti++;
        } else if (typ == 2) {
            while (!aplications[x].empty()) {
                visto[aplications[x].front()] = true;
                aplications[x].pop();
                noti--;
            }
        } else {
            while (!notifications.empty() && notifications.front().first <= x) {
                int j = notifications.front().first;
                int k = notifications.front().second;
                notifications.pop();
                if (!visto[j]) {
                    visto[j] = true;
                    aplications[k].pop();
                    noti--;
                }
            }
        }
        cout << noti << "\n";
    }
    return 0;
}