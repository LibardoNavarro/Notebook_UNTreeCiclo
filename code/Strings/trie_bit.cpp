#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+5;
const int bits = 30;
const int alpha = 2;

int to[maxn*bits][alpha],cnt[maxn*bits],act;
int conv(int x, int i){return ((x&(1<<i))?1:0);}

void init(){ 
	for(int i=0;i<=act;++i){
		memset(to[i],0,sizeof(to[i]));
		cnt[i]=0;
	}
	act=0;
}

void add(int x){
	int u=0;
	for(int i=bits;i>=0;--i){
		int c=conv(x,i);
		if(!to[u][c])to[u][c]=++act;
		cnt[u]++;
		u=to[u][c];
	}
	cnt[u]++;
}

int mini(int x){
	int u=0,ans=0;
	for(int i=bits;i>=0;--i){
		int c=conv(x,i);
		if(!to[u][c] || cnt[to[u][c]]==0){
			u=to[u][!c];
			ans+=(1<<i);
		}else{
			u=to[u][c];
		}
	}
	return ans;
}

