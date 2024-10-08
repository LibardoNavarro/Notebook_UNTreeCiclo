// CCW order
// if colineal are needed, use > in orient and remove repeated points
vector<pt> chull(vector<pt>& p){
	if(p.size() < 3) return p;
	
	vector<pt> r; //r.reserve(p.size());
	sort(p.begin(), p.end()); // first x, then y
 
	for(int i = 0; i < p.size(); i++){ // lower hull
		while(r.size() >= 2 && orient(r[r.size() - 2], p[i], r.back()) >= 0) r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
 
	int k = r.size();
	for(int i = p.size() - 1; i >= 0; --i){ // upper hull
		while(r.size() >= k + 2 && orient(r[r.size() - 2], p[i], r.back()) >= 0) r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
 
	return r;
}