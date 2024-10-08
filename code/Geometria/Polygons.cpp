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

void remove_col(vector<pt>& p){ // REVISAR
    vector<pt> s;
    for(int i = 0, n = p.size(); i < n; i++){
        if(!on_segment(p[(i-1+n) % n], p[(i+1) % n], p[i])) s.push_back(p[i]);
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
    if (a.size() > b.size()) swap(a, b);
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

lf intercircle(vector<pt>& p, circle c){ // area of intersection with circle // REVISAR
    lf r=0.;
    for(int i = 0, n = p.size(); i < n; i++){
        int j = (i + 1) % n;
        lf w = c.intertriangle(p[i],p[j]);
        if(cross((p[j] - c.o), (p[i] - c.o)) > 0) r += w;
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
