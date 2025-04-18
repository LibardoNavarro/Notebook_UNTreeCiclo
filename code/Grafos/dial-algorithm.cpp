const int maxn = 2e5+5;
vector<pair<int, int>> adj[maxn];

// O(n*k+m)
// bfs for edge weights in the range [0, k]
void bfs(int s, int n, int k){
	vector<queue<int>> qs(k+1, queue<int>());
	vector<bool> vis(n, false);
	vector<int> dist(n, 1e9);
	qs[0].push(s);
	dist[s]=0;
	int pos=0,num=1;
	while(num){
		while(qs[pos%(k+1)].empty())pos++;
		int u=qs[pos%(k+1)].front();
		qs[pos%(k+1)].pop();
		num--;
		if(vis[u])continue;
		vis[u]=true;
		for(auto [w,v]:adj[u]){
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				qs[dist[v]%(k+1)].push(v);
				num++;
			}
		}
	}
}