const int maxn = 2e6+5, alpha = 26, bits = 30;
int to[maxn][alpha],cnt[maxn],act;

void init(){ 
	for(int i=0;i<=act;++i){
		cnt[i]=0;
		// suf[i]=dad[i]=0;
		// adj[i].clear();
		memset(to[i], 0, sizeof(to[i]));
	}
	act=0;
}

int add(string& s){
	int u=0;
	for(char ch:s){
		int c=conv(ch);
		if(!to[u][c])to[u][c]=++act;
		u=to[u][c];
	}
	cnt[u]++;
	return u;
}

// Aho-Corasick
vector<int> adj[maxn]; // dad or suf
int dad[maxn],suf[maxn];

// O(sum(n)*alpha)
void build(){
	queue<int> q{{0}};
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<alpha;++i){
			int v=to[u][i];
			if(!v)to[u][i]=to[suf[u]][i];
			else q.push(v);
			if(!u || !v)continue;
			suf[v]=to[suf[u]][i];
			dad[v]=cnt[suf[v]]?suf[v]:dad[suf[v]];
		}
	}
	for(int i=1;i<=act;++i){
		adj[i].push_back(dad[i]);
		adj[dad[i]].push_back(i);
	}
}
