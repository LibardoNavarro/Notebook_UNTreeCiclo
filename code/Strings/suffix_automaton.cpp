// O(n*log(alpha))
// suf: suffix link (like aho if not match)
// len: length of the longest string in this state
// minlen: smallest string of node v = (v.suf==-1?0:v.suf.len) + 1
// end: if this state is terminal
// count different strings [i.suf.len+1, i.len]
// para saber cuantos substrings itnee a en b, ir procesando los 
// prefijos y al marcarlos procesar la cantidad visitando los sufijos de los nodos
// contribucion es u.len - u.suf.len, tener en cuenta con que len se llego
// puede ser un len2 para manejar eso min(u.len, u.len2)-u.suf.len

// a->b->c->b->c
// b->c
template<int alpha = 26>
struct SuffixAutomaton {
	struct Node {
		// array<int, alpha> to; TLE, add -> int conv(char ch)
		map<char, int> to;
		int len = 0, suf = 0; 
		bool end = false;
	};

	vector<Node> sa;
	int last = 0;
	ll substrs = 0;

	SuffixAutomaton(string &s) {
		sa.reserve(sz(s)*2);
		last = add_node();
		sa[0].suf = -1;
		for (char &c : s) add_char(c);
		for (int p = last; p; p = sa[p].suf) sa[p].end = 1;
	}

	int add_node() { sa.push_back({}); return sz(sa)-1; }

	void add_char(char c) {
		int u = add_node(), p = last;
		sa[u].len = sa[last].len + 1;
		while (p != -1 && !sa[p].to.count(c)) {
			sa[p].to[c] = u;
			substrs += p != 0 ? sa[p].len - sa[sa[p].suf].len : 1;
			p = sa[p].suf;
		}
		if (p != -1) {
			int q = sa[p].to[c];
			if (sa[p].len + 1 != sa[q].len) {
				int clone = add_node();
				sa[clone] = sa[q];
				sa[clone].len = sa[p].len + 1;
				sa[q].suf = sa[u].suf = clone;
				while (p != -1 && sa[p].to[c] == q) {
					sa[p].to[c] = clone;
					p = sa[p].suf;
				}
			} else sa[u].suf = q;
		}
		last = u;
	}

	// Aplicaciones 
	
	int dfs(int u){ // count
		if(sa[u].cnt!=-1)return sa[u].cnt;
		sa[u].cnt=sa[u].end;
		for(auto [_,v]:sa[u].to){
			sa[u].cnt+=dfs(v);
		}
		return sa[u].cnt;
	}

	void dfs2(int u){ // grade primero
		sa[u].pre--;
		if(sa[u].pre>0)return;
		for(auto [_,v]:sa[u].to){
			sa[v].cnt2+=sa[u].cnt2;
			dfs2(v);
		}
	}

	void dfs2(){
		vector<int> order(sz(sa)-1);
		for(int i=1;i<sz(sa);++i)order[i-1]=i;
		sort(order.begin(), order.end(), [&](int a, int b) { return sa[a].len > sa[b].len; });
		for(auto &i : order){
			// suf.cnt += i.cnt
		}
	}

	int lcs(string& t){
		int u=0,l=0,ans=0;
		for(char c:t){
			while(u && !sa[u].to.count(c)){
				u=sa[u].suf;
				l=sa[u].len;
			}
			if(sa[u].to.count(c)){
				u=sa[u].to[c];
				l++;
			}
			ans=max(ans, l);
		}
		return ans;
	}

	bool query(string& t){
		int u=0;
		for(char c:t){
			if(!sa[u].to.count(c))return false;
			u=sa[u].to[c];
		}
		return true;
	}

	void cyclic(string& t){ // dfs(0) primero
		int u=0,l=0;
		int m=sz(t);
		t+=t;
		unordered_set<int> s; // vector<bool>
		for(char ch:t){
			int c=conv(ch);
			while(u && !sa[u].to[c]){
				u=sa[u].suf;
				l=sa[u].len;
			}
			if(sa[u].to[c]){
				u=sa[u].to[c];
				l++;
			}
			if(l==m){
				s.insert(u);
				if(sa[u].minlen==m){
					u=sa[u].suf;
					l=sa[u].len;
				}else{
					l--;
				}
			}
		}
		ll ans=0;
		for(int u:s)ans+=sa[u].cnt;
		cout<<ans<<"\n";
	}
};	