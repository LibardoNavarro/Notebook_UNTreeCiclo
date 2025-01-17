// O(n)
struct SuffixTree{
	vector<map<char,int>> to;
	vector<int> pos,len,link; 
	int size=0,inf=1e9;
	string s; 

	int make(int _pos, int _len){
		to.push_back(map<char,int>());
		pos.push_back(_pos);
		len.push_back(_len);
		link.push_back(-1);
		return size++;
	}
	
	void add(int& p, int& lef, char c){ 
		s+=c;++lef;int lst=0;
		for(;lef;p?p=link[p]:lef--){ 
			while(lef>1 && lef>len[to[p][s[sz(s)-lef]]]){
				p=to[p][s[sz(s)-lef]],lef-=len[p]; 
			}
			char e=s[sz(s)-lef]; 
			int& q=to[p][e];
			if(!q){
				q=make(sz(s)-lef,inf),link[lst]=p,lst=0;
			}else{
				char t=s[pos[q]+lef-1]; 
				if(t==c){link[lst]=p;return;}
				int u=make(pos[q],lef-1); 
				to[u][c]=make(sz(s)-1,inf); 
				to[u][t]=q; 
				pos[q]+=lef-1; 
				if(len[q]!=inf)len[q]-=lef-1;
				q=u,link[lst]=u,lst=u;
			}
		}
	}

	SuffixTree(string& _s){
		make(-1,0);int p=0,lef=0;
		for(char c:_s)add(p,lef,c);
		add(p,lef,'$');
		s.pop_back();
	}

	int query(string& p){
		for(int i=0,u=0,n=sz(p);;){
			if(i==n || !to[u].count(p[i]))return i;
			u=to[u][p[i]];
			for(int j=0;j<len[u];++j){
				if(i==n || s[pos[u]+j]!=p[i])return i;
				i++;
			}
		}
	}

	vector<int> sa;
	void genSA(int x=0, int Len=0){
		if(!sz(to[x]))sa.push_back(pos[x]-Len);
		else for(auto t:to[x])genSA(t.second,Len+len[x]);
	}
};
