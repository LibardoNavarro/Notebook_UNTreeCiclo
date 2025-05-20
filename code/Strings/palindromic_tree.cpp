const int alpha = 26;
const char fc = 'a';

// tree.suf: the longest suffix-palindrome link
// tree.dad - tree.to: the parent palindrome by removing the first and last character
struct Node{
	int to[alpha];
	int len,suf,dep,cnt,dad;
};

// O(n*log(n))
struct PalindromicTree{
	vector<Node> tree; 
	string s;
	vector<int> palo; // longest suffix-palindrome in the position i
	int len,n,size; 
	int last; // max suffix palindrome
	// node 1 = root with len -1 for odd
	// node 2 = root with len 0 for even

	bool addLetter(int pos){
		int cur=last,curlen=0;
		int let=s[pos]-fc;
		while(true){
			curlen=tree[cur].len;
			if(pos-1-curlen>=0 && s[pos-1-curlen]==s[pos])break;  
			cur=tree[cur].suf;
		}      

		if(tree[cur].to[let]){  
			last=tree[cur].to[let];
			tree[last].cnt++;
			return false;
		}

		size++;
		last=size;
		tree[size].len=tree[cur].len+2;
		tree[cur].to[let]=size;
		tree[size].cnt=1;
		tree[size].dad=cur;

		if(tree[size].len==1){
			tree[size].suf=2;
			tree[size].dep=1;
			return true;
		}

		while(true){
			cur=tree[cur].suf;
			curlen=tree[cur].len;
			if(pos-1-curlen>=0 && s[pos-1-curlen]==s[pos]){
				tree[size].suf=tree[cur].to[let];
				break;
			}       
		}           

		tree[size].dep=1+tree[tree[size].suf].dep;
		return true;
	}

	PalindromicTree(string& s2, int n){
		tree.assign(n+4,Node());
		tree[1].len=-1;tree[1].suf=1;
		tree[2].len=0;tree[2].suf=1;
		size=2;last=2;s=s2;

		for(int i=0;i<n;i++){
			addLetter(i);
			palo.push_back(tree[last].len);
		}

		// Propagate counts up the suffix links
		for(int i=size;i>=3;i--){
			tree[tree[i].suf].cnt+=tree[i].cnt;
		}
	}
};
