const ll INF = 2e18;
const int D = 2; // dimension
 
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
		build(root, 0, sz(vptd) - 1);
	}
    
    // O(nlogn)
	void build(kd_node* &node, int l, int r){
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

		ll bAxis = 0;
		ll mRange = 0;
		for (int axis = 0; axis < D; ++axis) {
			ll minVal = INF, maxVal = -INF;
			for (int i = l; i <= r; ++i){
				minVal = min(minVal, (ll)arr[i].p[axis]);
				maxVal = max(maxVal, (ll)arr[i].p[axis]);
			}

			if (maxVal - minVal > mRange) {
				mRange = maxVal - minVal;
				bAxis = axis;
			}
		}
	  
		int mid = (l + r) / 2;
	  
		nth_element(arr.begin() + l, arr.begin() + mid, arr.begin() + r + 1, cmp_points(bAxis));
		node->p = arr[mid];
		node->axis = bAxis;
		build(node->left, l, mid);
		build(node->right, mid + 1, r);
	}
	
	void nearest(kd_node* node, ptd q, pair<ll, ptd> &ans){
		if(node == NULL) return;
	
		if(node->left == NULL && node->right == NULL) {
			if(!(q != node->p)) return; // avoid query point as answer
			
			if (ans.first > dis2(node->p, q)) ans = {dis2(node->p, q), node->p};
			
			return;
		}
		
		int axis = node->axis;
		int value = node->p.p[axis];
		
		if(q.p[axis] <= value){
			nearest(node->left, q, ans);
			ll diff = value - q.p[axis];
			if(diff * diff <= ans.ff) nearest(node->right, q, ans);
		}else{
			nearest(node->right, q, ans);
			ll diff = q.p[axis] - value;
			if(diff * diff <= ans.ff) nearest(node->left, q, ans);
		}
	}
    
    // O(logn) Returns {squared distance, nearest point}
	pair<ll, ptd> nearest(ptd q){
		pair<ll, ptd> ans = {INF, ptd()};
		nearest(root, q, ans);
		return ans;
	}
};
