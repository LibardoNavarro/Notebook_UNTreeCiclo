bool ccw(pt p, pt q, pt r) { // counter-clockwise
	return cross((q - p), (r - q)) > 0; // >= if colineal are needed 
}

struct upper {
	set<pt> se;
	set<pt>::iterator it;

	int is_under(pt p) { // 1 -> inside ; 2 -> border
		it = se.lower_bound(p);
		if (it == se.end()) return 0;
		if (it == se.begin()) return p == *it ? 2 : 0;
		if (ccw(p, *it, *prev(it))) return 1;
		return ccw(p, *prev(it), *it) ? 0 : 2;
	}
	void insert(pt p) {
		if (is_under(p)) return;

		if (it != se.end()) while (next(it) != se.end() and !ccw(*next(it), *it, p))
			it = se.erase(it);
		if (it != se.begin()) while (--it != se.begin() and !ccw(p, *it, *prev(it)))
			it = se.erase(it);

		se.insert(p);
	}
};

struct dyn_hull { // 1 -> inside ; 2 -> border
	upper U, L;

	int is_inside(pt p) {
		int u = U.is_under(p), l = L.is_under({-p.x, -p.y});
		if (!u or !l) return 0;
		return max(u, l);
	}
	void insert(pt p) {
		U.insert(p);
		L.insert({-p.x, -p.y});
	}
	int size() {
		int ans = U.se.size() + L.se.size();
		return ans <= 2 ? ans/2 : ans-2;
	}
};


// farthest_dynamic

vector<vector<pt>> pols;
 
// log^2(n) amortized (binary mergin)
void add(pt pi){
    vector<pt> pa = {pi};
	while(sz(pols) && sz(pols.back()) < 2 * sz(pa)){
        for(pt pi : pols.back()) pa.pb(pi);
		pols.pop_back();
	}
	vector<pt> ch = chull(pa);
	pols.pb(ch);
}


// log^2(n) 
lf query(pt &dir){
    lf maxi = LONG_LONG_MIN;
	for(vector<pt> &pol : pols){
		lf ans = dot(farthest(pol, dir), dir);
		maxi = max(maxi, ans);
	}
	return maxi;
}