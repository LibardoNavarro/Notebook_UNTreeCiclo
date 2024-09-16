const int alpha = 26;
const char fc = 'a';

// tree link is the longest suffix palindrome
// tree dad is the palindrome add to the right and left
struct Node{
	int next[alpha];
	int len,link,dep,cnt,dad;
};

// O(nlogn)
struct PalindromicTree{
	vector<Node> tree; 
	string s;
	int len,n;
	int size;	// node 1 - root with len -1, node 2 - root with len 0
	int suff;	// max suffix palindrome

	bool addLetter(int pos){
		int cur=suff,curlen=0;
		int let=s[pos]-fc;
		while(true){
			curlen=tree[cur].len;
			if(pos-1-curlen>=0 && s[pos-1-curlen]==s[pos])break;  
			cur=tree[cur].link;
		}      

		if(tree[cur].next[let]){  
			suff=tree[cur].next[let];
			tree[suff].cnt++;
			return false;
		}

		size++;
		suff=size;
		tree[size].len=tree[cur].len+2;
		tree[cur].next[let]=size;
		tree[size].cnt=1;
		tree[size].dad=cur;

		if(tree[size].len==1){
			tree[size].link=2;
			tree[size].dep=1;
			return true;
		}

		while(true){
			cur=tree[cur].link;
			curlen=tree[cur].len;
			if(pos-1-curlen>=0 && s[pos-1-curlen]==s[pos]){
				tree[size].link=tree[cur].next[let];
				break;
			}       
		}           

		tree[size].dep=1+tree[tree[size].link].dep;
		return true;
	}

	void build(string& s2, int n){
		tree.assign(n+4,Node());
		tree[1].len=-1;tree[1].link=1;
		tree[2].len=0;tree[2].link=1;
		size=2;suff=2;s=s2;

		for(int i=0;i<n;i++)addLetter(i);
		for(int i=size;i>=3;i--){
			tree[tree[i].link].cnt+=tree[i].cnt;
		}
	}
};
