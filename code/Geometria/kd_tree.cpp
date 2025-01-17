// given a set of points, answer queries of nearest point in O(log(n))
bool onx(pt a, pt b){return a.x < b.x;}
bool ony(pt a, pt b){return a.y < b.y;}
struct Node {
	pt pp;
	lf x0 = inf, x1 = -inf, y0 = inf, y1 = -inf;
	Node *first = 0, *second = 0;
 
	ll distance(pt p){
		ll x = min(max(x0, p.x), x1);
		ll y = min(max(y0, p.y), y1);
		return norm2(pt(x, y) - p);
	}
 
	Node(vector<pt>&& vp) : pp(vp[0]){
		for(pt p : vp){
			x0 = min(x0, p.x);
            x1 = max(x1, p.x);
			y0 = min(y0, p.y); 
            y1 = max(y1, p.y);
		}
		if(vp.size() > 1){
			sort(all(vp), x1 - x0 >= y1 - y0 ? onx : ony);
			int m = vp.size() / 2;
			first = new Node({vp.begin(), vp.begin() + m});
			second = new Node({vp.begin() + m, vp.end()});
		}
	}
};
 
struct KDTree {
	Node* root;
	KDTree(const vector<pt>& vp): root(new Node({all(vp)})){}
	pair<ll, pt> search(pt p, Node *node){
		if(!node->first){
			// avoid query point as answer
			// if(p.x == node->pp.x && p.y == node->pp.y) return {inf, pt()};
			return {norm2(p-node->pp), node->pp};
		}
		Node *f = node->first, *s = node->second;
		ll bf = f->distance(p), bs = s -> distance(p);
		if(bf > bs) swap(bf, bs), swap(f, s);
		auto best = search(p, f);
		if(bs < best.ff) best = min(best, search(p, s));
		return best;
	}
	pair<ll, pt> nearest(pt p){ return search(p, root); }
};
 