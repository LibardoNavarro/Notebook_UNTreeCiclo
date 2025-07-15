// O(n*log(alpha))
// suf: suffix link
// len: length of the longest string in this state
// end: if this state is terminal
struct SuffixAutomaton{
	vector<map<char,int>> to;
	vector<int> suf,len; 
	vector<bool> end;
	int last;

	SuffixAutomaton(string& s){
		to.push_back(map<char,int>());
		suf.push_back(-1);
		len.push_back(0);
		last=0;

		for(int i=0;i<sz(s);i++){
			to.push_back(map<char,int>());
			suf.push_back(0);
			len.push_back(i+1);
			int r=sz(to)-1;

			int p=last;
			while(p>=0 && to[p].find(s[i])==to[p].end()){
				to[p][s[i]]=r;
				p=suf[p];
			}
			if(p!=-1){
				int q=to[p][s[i]];
				if(len[p]+1==len[q]){
					suf[r]=q;
				}else{
					to.push_back(to[q]);
					suf.push_back(suf[q]); 
					len.push_back(len[p]+1);
					int qq=sz(to)-1;
					suf[q]=qq;
					suf[r]=qq;
					while(p>=0 && to[p][s[i]]==q){
						to[p][s[i]]=qq;
						p=suf[p];
					}
				}
			}
			last=r;
		}

		end.assign(sz(to), false);
		int p=last;
		while(p){
			end[p]=true;
			p=suf[p];
		}
	}
};
