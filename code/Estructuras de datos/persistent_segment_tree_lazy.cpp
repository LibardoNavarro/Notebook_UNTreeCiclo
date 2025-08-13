// O(n*log(n)) build
// O(log(n)) get, upd
// O((n+q)*log(n)) memory
typedef long long T;
struct Node {
	Node* left = nullptr; 
	Node* right = nullptr;
	T val = 0, prop = 0;  
};
typedef Node* PNode;
struct PerSegTree {
	vector<PNode> roots{}; 
	vector<T> vec{};  
	int n = 0;  

	T op(T a, T b){
		return a+b;
	}

	PNode newKid(PNode& curr) {
		PNode newNode = new Node();
		newNode->left = curr->left;
		newNode->right = curr->right;
		newNode->prop = curr->prop;
		newNode->val = curr->val;
		return newNode;
	}

	void lazy(int i, int j, PNode& curr) {
		if (!curr->prop) return;
		curr->val += ((T)(j - i + 1)) * curr->prop;
		if (i != j) {
			curr->left = newKid(curr->left);
			curr->right = newKid(curr->right);
			curr->left->prop += curr->prop;
			curr->right->prop += curr->prop;
		}
		curr->prop = 0;
	}

	PNode build(int i, int j) {
		PNode newNode = new Node();
		if (i == j) {
			newNode->val = vec[i];
		} else {
			int mid = i + (j - i) / 2;
			PNode leftt = build(i, mid);
			PNode right = build(mid + 1, j);
			newNode->val = op(leftt->val, right->val);
			newNode->left = leftt;
			newNode->right = right;
		}
		return newNode;
	}

	PNode upd(int i, int j, int l, int r, T value, PNode& curr) {
		lazy(i, j, curr);
		if (i >= l && j <= r) {
			PNode newNode = newKid(curr);
			newNode->prop += value;
			lazy(i, j, newNode);
			return newNode;
		}
		if (i > r || j < l) {
			return curr;
		}
		PNode newNode = new Node();
		int mid = i + (j - i) / 2;
		newNode->left = upd(i, mid, l, r, value, curr->left);
		newNode->right = upd(mid + 1, j, l, r, value, curr->right);
		newNode->val = op(newNode->left->val, newNode->right->val);
		return newNode;
	}

	T get(int i, int j, int l, int r, PNode& curr) {
		lazy(i, j, curr);
		if (j < l || r < i) {
			return 0;
		}
		if (i >= l && j <= r) {
			return curr->val;
		}
		int mid = i + (j - i) / 2;
		return op(get(i, mid, l, r, curr->left), get(mid + 1, j, l, r, curr->right));
	}

	// public methods 
	void build(vector<T>& vec) {
		if (vec.empty()) return;
		n = vec.size();
		this->vec = vec;
		auto root = build(0, n - 1);
		roots.push_back(root);
	}

	void upd(int l, int r, T value, int time) {
		roots.push_back(upd(0, n - 1, l, r, value, roots[time]));
	}

	T get(int l, int r, int time) {
		return get(0, n - 1, l, r, roots[time]);
	}

	int size() { return roots.size(); }
};
