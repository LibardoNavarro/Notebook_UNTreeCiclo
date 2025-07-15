const int maxn = 2e6+5;
const int alpha = 26; 

int to[maxn][alpha]; // to[u][c]: node u edge with the letter c
int cnt[maxn]; // count of word ending in this node
int act; // trie node cound
int conv(char ch){return ((ch>='a' && ch<='z')?ch-'a':ch-'A'+26);} 

void init(){ 
	for(int i=0;i<=act;++i){
		cnt[i]=0;
		memset(to[i],0,sizeof(to[i]));
	}
	act=0;
}

void add(string& s){
	int u=0;
	for(char ch:s){
		int c=conv(ch);
		if(!to[u][c])to[u][c]=++act;
		u=to[u][c];
	}
	cnt[u]++;
}
