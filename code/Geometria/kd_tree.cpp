const ll INF = 2e18;
const int D = 3; // dimension
 
struct ptd{
	int p[D];
	bool operator !=(const ptd &a) const {
		bool ok = 1;
		for(int i = 0; i < D; i++) ok &= (p[i] == a.p[i]);
		return !ok;
	}
};
 
struct kd_node{
	ptd p;
	int axis;
	kd_node *left, *right;
};
 
struct cmp_points {
	int axis;
	cmp_points(){}
	cmp_points(int x): axis(x){}
	
	bool operator ()(const ptd &a, const ptd &b) const {
		return a.p[axis] < b.p[axis];
	}
};
 
ll dis2(ptd a, ptd b) {
	ll ans = 0;
	for(int i = 0; i < D; i++) ans += (a.p[i] - b.p[i]) * 1ll * (a.p[i] - b.p[i]);
	return ans;
}
 
struct KDTree{
	vector<ptd> arr;
	kd_node* root;
 
	KDTree(vector<ptd> &vptd): arr(vptd){	
		build(root, 0, sz(vptd) - 1, 0);
	}
    
    // O(nlogn)
	void build(kd_node* &node, int l, int r, int axis) {
		if(l > r) {
			node = nullptr;
			return;
		}
	  
		node = new kd_node();
	  
		if(l == r) {
			node->p = arr[l];
			node->left = nullptr;
			node->right = nullptr;
			return;
		}
	  
		int mid = (l + r) / 2;
	  
		nth_element(arr.begin() + l, arr.begin() + mid, arr.begin() + r + 1, cmp_points(axis));
		node->p = arr[mid];
		node->axis = axis;
		build(node->left, l, mid, (axis + 1) % D);
		build(node->right, mid + 1, r, (axis + 1) % D);
	}
	
	void nearest(kd_node* node, ptd q, ll &ans) {
		if(node == NULL) return;
	
		if(node->left == NULL && node->right == NULL) {
			if(q != node->p) ans = min(ans, dis2(node->p, q)); // CUIDADO
			return;
		}
		
		int value = node->p.p[node->axis];
		
		if(q.p[node->axis] <= value) {
			nearest(node->left, q, ans);
			if(q.p[node->axis] + sqrt(ans) >= value) nearest(node->right, q, ans);
		}
		else {
			nearest(node->right, q, ans);
			if(q.p[node->axis] - sqrt(ans) <= value) nearest(node->left, q, ans);
		}
	}
    
    // O(logn) Returns the squared distance to the nearest point
	ll nearest(ptd q){
		ll ans = INF;
		nearest(root, q, ans);
		return ans;
	}
};