const int alpha = 26;
const char fc = 'a';

// tree suf is the longest suffix palindrome
// tree dad is the palindrome add c to the right and left
struct Node{
	int next[alpha];
	int len,suf,dep,cnt,dad;
};

// O(nlogn)
struct PalindromicTree{
	vector<Node> tree; 
	string s;
	int len,n;
	int size; // node 1 - root with len -1, node 2 - root with len 0
	int last; // max suffix palindrome

	bool addLetter(int pos){
		int cur=last,curlen=0;
		int let=s[pos]-fc;
		while(true){
			curlen=tree[cur].len;
			if(pos-1-curlen>=0 && s[pos-1-curlen]==s[pos])break;  
			cur=tree[cur].suf;
		}      

		if(tree[cur].next[let]){  
			last=tree[cur].next[let];
			tree[last].cnt++;
			return false;
		}

		size++;
		last=size;
		tree[size].len=tree[cur].len+2;
		tree[cur].next[let]=size;
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
				tree[size].suf=tree[cur].next[let];
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
		}

		for(int i=size;i>=3;i--){
			tree[tree[i].suf].cnt+=tree[i].cnt;
		}
	}
};
