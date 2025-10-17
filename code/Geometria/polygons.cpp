// add Points Lines Segments Circles

// points in polygon(vector<pt>) ccw or cw
enum {OUT, IN, ON};

lf area(vector<pt>& p){
	lf r = 0.;
	for(int i = 0, n = p.size(); i < n; ++i){
		r += cross(p[i], p[(i + 1) % n]);
	}
	return r / 2; // negative if CW, positive if CCW
}

lf perimeter(vector<pt>& p) {
	lf per = 0;
	for (int i = 0, n = p.size(); i < n; ++i){
		per += norm(p[i] - p[(i + 1) % n]);
	}
	return per;
}

bool is_convex(vector<pt>& p) {
	bool pos = 0, neg = 0;
	for (int i = 0, n = p.size(); i < n; i++) {
		int o = orient(p[i], p[(i + 1) % n], p[(i + 2) % n]);
		if (o > 0) pos = 1;
		if (o < 0) neg = 1;
	}
	return !(pos && neg);
}

int point_in_polygon(vector<pt>& pol, pt& p){
	int wn = 0;
	for(int i = 0, n = pol.size(); i < n; ++i) {
		lf c = orient(p, pol[i], pol[(i + 1) % n]);
		if(fabsl(c) <= E0 && dot(pol[i] - p, pol[(i + 1) % n] - p) <= E0) return ON; // on segment
		
		if(c > 0 && pol[i].y <= p.y + E0 && pol[(i + 1) % n].y - p.y > E0) ++wn;
		if(c < 0 && pol[(i + 1) % n].y <= p.y + E0 && pol[i].y - p.y > E0) --wn;
	}
	return wn ? IN : OUT;
}

// O(logn) polygon CCW, remove collinear
int point_in_convex_polygon(const vector<pt> &pol, const pt &p){
	int low = 1, high = pol.size() - 1;
	while(high - low > 1){
		int mid = (low + high) / 2;
		if(orient(pol[0], pol[mid], p) >= -E0) low = mid;
		else high = mid;
	}
	if(orient(pol[0], pol[low], p) < -E0) return OUT;
	if(orient(pol[low], pol[high], p) < -E0) return OUT;
	if(orient(pol[high], pol[0], p) < -E0) return OUT;

	if(low == 1 && orient(pol[0], pol[low], p) <= E0) return ON;
	if(orient(pol[low], pol[high], p) <= E0) return ON;
	if(high == (int) pol.size() -1 && orient(pol[high], pol[0], p) <= E0) return ON;
	return IN;	
}

// convex polygons in some order (CCW, CW)
vector<pt> minkowski(vector<pt> P, vector<pt> Q) {
	rotate(P.begin(), min_element(P.begin(), P.end()), P.end());
	rotate(Q.begin(), min_element(Q.begin(), Q.end()), Q.end());

	P.push_back(P[0]), P.push_back(P[1]);
	Q.push_back(Q[0]), Q.push_back(Q[1]);

	vector<pt> ans; 
	size_t i = 0, j = 0;
	while(i < P.size() - 2 || j < Q.size() - 2){
		ans.push_back(P[i] + Q[j]);
		lf dt = cross(P[i + 1] - P[i], Q[j + 1] - Q[j]);
		if(dt >= E0 && i < P.size() - 2) ++i;
		if(dt <= E0 && j < Q.size() - 2) ++j;
	}
	return ans;
}

pt centroid(vector<pt>& p){
	pt c{0, 0};
	lf scale = 6. * area(p);
	for (int i = 0, n = p.size(); i < n; ++i){
		c = c + (p[i] + p[(i + 1) % n]) * cross(p[i], p[(i + 1) % n]);
	}
	return c / scale;
}

void normalize(vector<pt>& p) { // polygon CCW
	int bottom = min_element(p.begin(), p.end()) - p.begin();
	vector<pt> tmp(p.begin() + bottom, p.end());
	tmp.insert(tmp.end(), p.begin(), p.begin()+bottom);
	p.swap(tmp);
	bottom = 0;
}

void remove_col(vector<pt>& p){
	vector<pt> s;
	for(int i = 0, n = p.size(); i < n; i++){
		if(!on_segment(p[(i - 1 + n) % n], p[(i + 1) % n], p[i])) s.push_back(p[i]);
	}
	p.swap(s);
}

void delete_repetead(vector<pt>& p){
	vector<pt> aux;
	sort(p.begin(), p.end());
	for (pt &pi : p){
		if (aux.empty() || aux.back() != pi) aux.push_back(pi);
	} 
	p.swap(aux);
}

pt farthest(vector<pt>& p, pt v){ // O(log(n)) only CONVEX, v: dir
	int n = p.size();
	if(n < 10){
		int k = 0;
		for(int i = 1; i < n; i++) if(dot(v, (p[i] - p[k])) > EPS) k = i;
		return p[k];
	}
	pt a = p[1] - p[0];
	int s = 0, e = n, ua = dot(v, a) > EPS;
	if(!ua && dot(v, (p[n - 1] - p[0])) <= EPS) return p[0];
	while(1){
		int m = (s + e) / 2; 
		pt c = p[(m + 1) % n] - p[m];
		int uc = dot(v, c) > EPS;
		if(!uc && dot(v, (p[(m - 1 + n) % n] - p[m])) <= EPS) return p[m];
		if(ua && (!uc || dot(v, (p[s] - p[m])) > EPS)) e = m;
		else if(ua || uc || dot(v, (p[s] - p[m])) >= -EPS) s = m, a = c, ua = uc;
		else e = m;
		assert(e > s + 1);
	}
}

vector<pt> cut(vector<pt>& p, line l){ 
	// cut CONVEX polygon by line l
	// returns part at left of l.pq
	vector<pt> q;  
	for(int i = 0, n = p.size(); i < n; i++) {
		int d0 = sign(l.side(p[i]));
		int d1 = sign(l.side(p[(i + 1) % n]));
		if(d0 >= 0) q.push_back(p[i]);

		line m(p[i], p[(i + 1) % n]);
		if(d0 * d1 < 0 && !(abs(cross(l.v, m.v)) <= EPS)){
			q.push_back((inter_ll(l, m)));
		}
	}
	return q;
}

// O(n)
vector<pair<int, int>> antipodal(vector<pt>& p){
	vector<pair<int, int>> ans;
	int n = p.size();
	if (n == 2) ans.push_back({0, 1});
	if (n < 3) return ans;
	auto nxt = [&](int x){ return (x + 1 == n ? 0 : x + 1); };
	auto area2 = [&](pt a, pt b, pt c){ return cross(b - a, c - a); };
	int b0 = 0;
	while (abs(area2(p[n - 1], p[0], p[nxt(b0)])) > abs(area2(p[n - 1], p[0], p[b0]))) ++b0;
	for (int b = b0, a = 0; b != 0 && a <= b0; ++a) {
		ans.push_back({a, b});
		while (abs(area2(p[a], p[nxt(a)], p[nxt(b)])) > abs(area2(p[a], p[nxt(a)], p[b]))){
			b = nxt(b);
			if (a != b0 || b != 0) ans.push_back({a, b});
			else return ans;
		}
		if (abs(area2(p[a], p[nxt(a)], p[nxt(b)])) == abs(area2(p[a], p[nxt(a)], p[b]))){
			if (a != b0 || b != n - 1) ans.push_back({a, nxt(b)});
			else ans.push_back({nxt(a), b});
		}
	}
	return ans;
}

// O(n)
// square distance of most distant points, prereq: convex, ccw, NO COLLINEAR POINTS
lf callipers(vector<pt>& p){ 
	int n = p.size();
	lf r = 0;     
	for(int i = 0, j = n < 2 ? 0 : 1; i < j; ++i){
		for(;;j = (j + 1) % n){
			r = max(r, norm2(p[i] - p[j]));
			if(cross((p[(i + 1) % n] - p[i]), (p[(j + 1) % n] - p[j])) <= EPS) break;
		}
	}

	return r;
}

// O(n + m) max_dist between 2 points (pa, pb) of 2 Convex polygons (a, b)
lf rotating_callipers(vector<pt>& a, vector<pt>& b){ // REVISAR
	if (a.size() > b.size()) swap(a, b); // <- del or add
	pair<ll, int> start = {-1, -1};
	if(a.size() == 1) swap(a, b);
	for(int i = 0; i < a.size(); i++) start = max(start, {norm2(b[0] - a[i]), i});
	if(b.size() == 1) return start.first;

	lf r = 0;
	for(int i = 0, j = start.second; i < b.size(); ++i){
		for(;; j = (j + 1) % a.size()){
			r = max(r, norm2(b[i] - a[j]));
			if(cross((b[(i + 1) % b.size()] - b[i]), (a[(j + 1) % a.size()] - a[j])) <= EPS) break;
		}
	}
	return r;
}

lf intercircle(vector<pt>& p, circle c){ // area of intersection with circle
	lf r=0.;
	for(int i = 0, n = p.size(); i < n; i++){
		int j = (i + 1) % n;
		lf w = intertriangle(c, p[i], p[j]);
		if(cross((p[j] - c.center), (p[i] - c.center)) > 0) r += w;
		else r -= w;
	}
	return abs(r);
}

ll pick(vector<pt>& p){
	ll boundary = 0;
	for (int i = 0, n = p.size(); i < n; i++) {
		int j = (i + 1 == n ? 0 : i + 1);
		boundary += __gcd((ll)abs(p[i].x - p[j].x), (ll)abs(p[i].y - p[j].y));
	}
	return abs(area(p)) + 1 - boundary / 2;
}

// minimum distance between two parallel lines (non necessarily axis parallel)
// such that the polygon can be put between the lines
// O(n) CCW polygon 
lf width(vector<pt> &p) {
    int n = (int)p.size();
    if (n <= 2) return 0;
    lf ans = inf;
    int i = 0, j = 1;
    while (i < n){
        while (cross(p[(i + 1) % n] - p[i], p[(j + 1) % n] - p[j]) >= 0) j = (j + 1) % n;
        line l1(p[i], p[(i + 1) % n]);
        ans = min(ans, l1.dist(p[j]));
        i++;
    }
    return ans;
}

// O(n) {minimum perimeter, minimum area} CCW polygon
pair<ld, ld> minimum_enclosing_rectangle(vector<pt> &p) {
	int n = p.size();
	if (n <= 2) return {perimeter(p), 0};
	int mndot = 0; 
    lf tmp = dot(p[1] - p[0], p[0]);
	for (int i = 1; i < n; i++) {
		if (dot(p[1] - p[0], p[i]) <= tmp) {
			tmp = dot(p[1] - p[0], p[i]);
			mndot = i;
		}
	}
	ld ansP = inf;
	ld ansA = inf;
	int i = 0, j = 1, mxdot = 1;
	while (i < n) {
		pt cur = p[(i + 1) % n] - p[i];
        while (cross(cur, p[(j + 1) % n] - p[j]) >= 0) j = (j + 1) % n;
        while (dot(p[(mxdot + 1) % n], cur) >= dot(p[mxdot], cur)) mxdot = (mxdot + 1) % n;
        while (dot(p[(mndot + 1) % n], cur) <= dot(p[mndot], cur)) mndot = (mndot + 1) % n;
        line l1(p[i], p[(i + 1) % n]);

        // minimum perimeter
        ansP = min(ansP, 2.0 * ((dot(p[mxdot], cur) / norm(cur) - dot(p[mndot], cur) / norm(cur)) + l1.dist(p[j])));
        // minimum area
        ansA = min(ansA, (dot(p[mxdot], cur) / norm(cur) - dot(p[mndot], cur) / norm(cur)) * l1.dist(p[j]));
        i++;
    }

    return {ansP, ansA};
}

// maximum distance from a convex polygon to another convex polygon
lf maximum_dist_from_polygon_to_polygon(vector<pt> &u, vector<pt> &v){ //O(n)
    int n = (int)u.size(), m = (int)v.size();
    lf ans = 0;
    if (n < 3 || m < 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) ans = max(ans, dis2(u[i], v[j]));
        }
        return sqrt(ans);
    }
    if (u[0].x > v[0].x) swap(n, m), swap(u, v);
    int i = 0, j = 0, step = n + m + 10;
    while (j + 1 < m && v[j].x < v[j + 1].x) j++ ;
    while (step--) {
        if (cross(u[(i + 1) % n] - u[i], v[(j + 1) % m] - v[j]) >= 0) j = (j + 1) % m;
        else i = (i + 1) % n;
        ans = max(ans, dis2(u[i], v[j]));
    }
    return sqrt(ans);
}

// -----------------------------------------------------------

pt project_from_point_to_seg(pt a, pt b, pt c) {
    double r = dis2(a, b);
    if (sign(r) == 0) return a;
    r = dot(c - a, b - a) / r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b - a) * r;
}
// minimum distance from point c to segment ab
lf pt_to_seg(pt a, pt b, pt c) {
    return dis(c, project_from_point_to_seg(a, b, c));
}

pair<pt, int> point_poly_tangent(vector<pt> &p, pt Q, int dir, int l, int r) {
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        bool pvs = sign(orient(Q, p[mid], p[mid - 1])) != -dir;
        bool nxt = sign(orient(Q, p[mid], p[mid + 1])) != -dir;
        if (pvs && nxt) return {p[mid], mid};
        if (!(pvs || nxt)) {
            auto p1 = point_poly_tangent(p, Q, dir, mid + 1, r);
            auto p2 = point_poly_tangent(p, Q, dir, l, mid - 1);
            return sign(orient(Q, p1.first, p2.first)) == dir ? p1 : p2;
        }
        if (!pvs) {
            if (sign(orient(Q, p[mid], p[l])) == dir)  r = mid - 1;
            else if (sign(orient(Q, p[l], p[r])) == dir) r = mid - 1;
            else l = mid + 1;
        }
        if (!nxt) {
            if (sign(orient(Q, p[mid], p[l])) == dir)  l = mid + 1;
            else if (sign(orient(Q, p[l], p[r])) == dir) r = mid - 1;
            else l = mid + 1;
        }
    }
    pair<pt, int> ret = {p[l], l};
    for (int i = l + 1; i <= r; i++) ret = sign(orient(Q, ret.first, p[i])) != dir ? make_pair(p[i], i) : ret;
    return ret;
}
// (ccw, cw) tangents from a point that is outside this convex polygon
// returns indexes of the points
// ccw means the tangent from Q to that point is in the same direction as the polygon ccw direction
pair<int, int> tangents_from_point_to_polygon(vector<pt> &p, pt Q){
    int ccw = point_poly_tangent(p, Q, 1, 0, (int)p.size() - 1).second;
    int cw = point_poly_tangent(p, Q, -1, 0, (int)p.size() - 1).second;
    return make_pair(ccw, cw);
}

// minimum distance from a point to a convex polygon
// it assumes point lie strictly outside the polygon
lf dist_from_point_to_polygon(vector<pt> &p, pt z) {
    lf ans = inf;
    int n = p.size();
    if (n <= 3) {
        for(int i = 0; i < n; i++) ans = min(ans, pt_to_seg(p[i], p[(i + 1) % n], z));
        return ans;
    }
    pair<int, int> dum = tangents_from_point_to_polygon(p, z);
    int r = dum.first;
    int l = dum.second;
    if(l > r) r += n;
    while (l < r) {
        int mid = (l + r) >> 1;
        lf left = dis2(p[mid % n], z), right= dis2(p[(mid + 1) % n], z);
        ans = min({ans, left, right});
        if(left < right) r = mid;
        else l = mid + 1;
    }
    ans = sqrt(ans);
    ans = min(ans, pt_to_seg(p[l % n], p[(l + 1) % n], z));
    ans = min(ans, pt_to_seg(p[l % n], p[(l - 1 + n) % n], z));
    return ans;
}

// minimum distance from a convex polygon to another convex polygon
// the polygon doesnot overlap or touch
lf dist_from_polygon_to_polygon(vector<pt> &p1, vector<pt> &p2) { // O(n log n)
    lf ans = inf;
    for (int i = 0; i < p1.size(); i++) {
        ans = min(ans, dist_from_point_to_polygon(p2, p1[i]));
    }
    for (int i = 0; i < p2.size(); i++) {
        ans = min(ans, dist_from_point_to_polygon(p1, p2[i]));
    }
    return ans;
}


// it returns a point such that the sum of distances
// from that point to all points in p  is minimum
// O(n log^2 MX)
PT geometric_median(vector<PT> p) {
	auto tot_dist = [&](PT z) {
	    double res = 0;
	    for (int i = 0; i < p.size(); i++) res += dist(p[i], z);
	    return res;
	};
	auto findY = [&](double x) {
	    double yl = -1e5, yr = 1e5;
	    for (int i = 0; i < 60; i++) {
	        double ym1 = yl + (yr - yl) / 3;
	        double ym2 = yr - (yr - yl) / 3;
	        double d1 = tot_dist(PT(x, ym1));
	        double d2 = tot_dist(PT(x, ym2));
	        if (d1 < d2) yr = ym2;
	        else yl = ym1;
	    }
	    return pair<double, double> (yl, tot_dist(PT(x, yl)));
	};
    double xl = -1e5, xr = 1e5;
    for (int i = 0; i < 60; i++) {
        double xm1 = xl + (xr - xl) / 3;
        double xm2 = xr - (xr - xl) / 3;
        double y1, d1, y2, d2;
        auto z = findY(xm1); y1 = z.first; d1 = z.second;
        z = findY(xm2); y2 = z.first; d2 = z.second;
        if (d1 < d2) xr = xm2;
        else xl = xm1;
    }
    return {xl, findY(xl).first };
}

// ear decomposition, O(n^3) but faster
vector<vector<pt>> triangulate(vector<pt> p) {
	vector<vector<pt>> v;

	while (p.size() >= 3){
		for (int i = 0, n = p.size(); i < n; i++){
			int pre = i == 0 ? n - 1 : i - 1;;
			int nxt = i == n - 1 ? 0 : i + 1;;
			lf ori = orient(p[i], p[pre], p[nxt]);

			if (ori < 0){
				int ok = 1;
				for (int j = 0; j < n; j++){
					if (j == i || j == pre || j == nxt)continue;
					vector<pt> tr = {p[i], p[pre], p[nxt]};
					if (point_in_polygon(tr , p[j]) != OUT){
						ok = 0;
						break;
					}
				}

				if (ok){
					v.push_back({p[pre], p[i], p[nxt]});
					p.erase(p.begin() + i);
					break;
				}
			}
		}
	}
	return v;
}

// CH DP
// vecs contains all vectors u -> v that lie within the original polygon
sort(vecs.begin(), vecs.end(), cmp);
for (auto [u, v] : vecs)
    for (int s = 0; s < n; s++)
        dp[s][v] += dp[s][u];

// Suma del area de todos los triangulos de un poligono
int main() { 
	int n; cin >> n;
 
	vector<pt> pts(n);
 
	forx(i, n) cin >> pts[i].x >> pts[i].y;
	
	vector<pt> pref(n + 1);
 
	for(int i = 1; i < n + 1; ++i){
		pref[i] = pref[i - 1] + pts[i - 1]; 
	}
 
	ld totalT = 0;
 
	for(ll i = 0; i < n; i++){
		pt p1 = (pts[i] * (ld)i) - pref[i];
		pt p2 = (pref[n] - pref[i + 1]) - (pts[i] * (ld)(n - 1 - i));
 
		totalT += cross(p1, p2);
	}

	// area = totalT / 2
	
}