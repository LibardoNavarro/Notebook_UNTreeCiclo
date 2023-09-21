#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
vector<bool> visited;
vector<vi> adj; 
vii aristas;
vi tin, low;
int n,m,a,b,timer; 

void IS_BRIDGE(int v, int to){
  aristas.push_back({v, to});
}

void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	for (int to : adj[v]) {
		if (to == p) continue;
		if (visited[to])low[v] = min(low[v], tin[to]);
		else {
				dfs(to, v);
				low[v] = min(low[v], low[to]);
				if (low[to] > tin[v])IS_BRIDGE(min(v,to), max(v,to));
		}
	}
}

void find_bridges() {
	timer = 0;
	visited.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!visited[i])dfs(i);
	}
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
while(cin>>n>>m, n!=0 && m!=0){
	adj.clear();aristas.clear();
	for(int i=0;i<n;i++)adj.push_back(vi());
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	find_bridges();
	cout<<sz(aristas);
	sort(aristas.begin(), aristas.end());
	for(ii ar:aristas)cout<<" "<<ar.first<<" "<<ar.second;
	cout<<"\n";
}
return 0;
}