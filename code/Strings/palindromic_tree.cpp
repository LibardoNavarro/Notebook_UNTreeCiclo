const int alpha = 26;
const char mini = 'a';

// tree.suf: the longest suffix-palindrome link
// tree.dad - tree.to: the parent palindrome by removing the first and last character
// node 0 = root with len -1 for odd
// node 1 = root with len 0 for even
struct Node {
    int to[alpha], suf, len, cnt, dad;
    Node(int x, int l = 0, int c = 1): len(x), suf(l), cnt(c) {
        memset(to, 0, sizeof(to));
    }
    int& operator [] (int i) { return to[i]; }
};

struct PalindromicTree {
    vector<Node> tree;
	vector<int> palo; // longest suffix-palindrome in the position i
    string s;
    int n,last; // max suffix palindrome

    PalindromicTree(string t = "") {
        n = last = 0;
        tree.push_back(Node(-1));
        tree.push_back(Node(0));
		for(char& c:t) add_char(c);
		// Propagate counts up the suffix links
		for(int i=sz(tree)-1;i>=2;i--){
			tree[tree[i].suf].cnt+=tree[i].cnt;
		}
    }

    int getsuf(int p) {
        while (n - tree[p].len - 1 < 0 || s[n - tree[p].len - 1] != s[n])
			p = tree[p].suf;
        return p;
    }

    void add_char(char ch) {
        s.push_back(ch);
        int p = getsuf(last), c = ch - mini;
        if (!tree[p][c]) {
            int suf = getsuf(tree[p].suf);
            suf = max(1, tree[suf][c]);
            tree[p][c] = sz(tree);
            tree.push_back(Node(tree[p].len + 2, suf, 0));
        }
        last = tree[p][c];
        tree[last].dad = p;
        tree[last].cnt++;n++;
		palo.push_back(tree[last].len);
    }
};