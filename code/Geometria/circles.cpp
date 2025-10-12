// add Lines Points

enum {OUT, IN, ON};

struct circle {
	pt center; lf r;
	// (x - xo)^2 + (y - yo)^2 = r^2

	circle(pt c, lf r): center(c), r(r){};

	// circle that passes through abc
	circle(pt a, pt b, pt c) {
		b = b - a, c = c - a;
		assert(cross(b, c) != 0); // no circumcircle if A, B, C aligned
		pt cen = a + rot90(b * norm2(c) - c * norm2(b)) / cross(b, c) / 2;
		center = cen;
		r = norm(a - cen);
	}

	// diameter = segment pq 
	circle(pt p, pt q) {
		center = (p + q) * 0.5L;
		r = dis(p, q) * 0.5L;
	}

	int contains(pt &p) {
		lf det = r * r - dis2(center, p);
		if(fabsl(det) <= EPS) return ON;
		return (det > EPS ? IN : OUT);
	}

	bool in(circle c){ return norm(center - c.center) + r <= c.r + EPS; }  // non strict

};

// centers of the circles that pass through ab and has radius r
vector<pt> centers(pt a, pt b, lf r) {
	if (norm(a - b) > 2 * r + EPS) return {};
	pt m = (a + b) / 2;
	double f = sqrt(r * r / norm2(a - m) - 1);
	pt c = rot90(a - m) * f;
	return {m - c, m + c};
}

vector<pt> inter_cl(circle c, line l){
	vector<pt> s;
	pt p = l.proj(c.center);
	lf d = norm(p - c.center);
	if(d - EPS > c.r) return s;
	if(abs(d - c.r) <= EPS){ s.push_back(p); return s; }
	d=sqrt(c.r * c.r - d * d);
	s.push_back(p + normalize(l.v) * d);
	s.push_back(p - normalize(l.v) * d);
	return s;
}

vector<pt> inter_cc(circle c1, circle c2) {
	pt dir = c2.center - c1.center;
	lf d2 = dis2(c1.center, c2.center);

	if(d2 <= E0) {
		//assert( fabsl( c1.r - c2.r ) > E0 );
		return {};
	}

	lf td = 0.5L * ( d2 + c1.r * c1.r - c2.r * c2.r );
	lf h2 = c1.r * c1.r - td / d2 * td;

	pt p = c1.center + dir * (td / d2);
	if(fabsl( h2 ) < EPS) return {p};
	if(h2 < 0.0L) return {};

	pt dir_h = rot90(dir) * sqrtl(h2 / d2);
	
	return {p + dir_h, p - dir_h}; 
}

//compute intersection of line through points a and b with
//circle centered at c with radius r > 0
vector<pt> circle_line_intersection(pt c, lf r, pt a, pt b) {
    vector<pt> ret;
    b = b - a; a = a - c;
    lf A = dot(b, b), B = dot(a, b);
    lf C = dot(a, a) - r * r, D = B * B - A * C;
    if (D < -EPS) return ret;
    ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
    if (D > EPS) ret.push_back(c + a + b * (-B - sqrt(D)) / A);
    return ret;
}

// circle-line inter = 1, inner: 1 = oxo 0 = o=o 
vector<pair<pt, pt>> tangents(circle c1, circle c2, bool inner){
	vector<pair<pt, pt>> out;
	if (inner) c2.r = -c2.r; // inner tangent
	pt d = c2.center - c1.center;
	double dr = c1.r - c2.r, d2 = norm2(d), h2 = d2 - dr * dr;
	if (d2 == 0 || h2 < 0) { assert(h2 != 0); return {}; } // (identical)
	for (double s : {-1, 1}) {
		pt v = (d * dr + rot90(d) * sqrt(h2) * s) / d2;
		out.push_back({c1.center + v * c1.r, c2.center + v * c2.r});
	}
	return out; // if size 1: circle are tangent
}

// circle targent passing through pt p
pair<pt, pt> tangent_through_pt(circle c, pt p){
	pair<pt, pt> out;
	double d = norm2(p - c.center);
	if (d < c.r) return {};
	pt base = c.center - p;
	double w = sqrt(norm2(base) - c.r * c.r);
	pt a = {w, c.r}, b = {w, -c.r};
	pt s = p + base * a / norm2(base) * w;
	pt t = p + base * b / norm2(base) * w;
	out = {s, t};
	return out;
}

lf safeAcos(lf x) {
	if (x < -1.0) x = -1.0;
	if (x > 1.0) x = 1.0;
	return acos(x);
}

lf areaOfIntersectionOfTwoCircles(circle c1, circle c2){
	lf r1 = c1.r, r2 = c2.r, d = dis(c1.center, c2.center);
	if(d >= r1 + r2) return 0.0L;
	if(d <= fabsl(r2 - r1)) return PI * (r1 < r2 ? r1 * r1 : r2 * r2);
	lf alpha = safeAcos((r1 * r1 - r2 * r2 + d * d) / (2.0L * d * r1));
	lf betha = safeAcos((r2 * r2 - r1 * r1 + d * d) / (2.0L * d * r2));
	lf a1 = r1 * r1 * (alpha - sinl(alpha) * cosl(alpha));
	lf a2 = r2 * r2 * (betha - sinl(betha) * cosl(betha));
	return a1 + a2;
};

lf intertriangle(circle& c, pt a, pt b){ // area of intersection with oab
	if(abs(cross((c.center - a), (c.center - b))) <= EPS) return 0.;
	vector<pt> q = {a}, w = inter_cl(c, line(a, b));
	if(w.size() == 2) for(auto p: w) if(dot((a - p), (b - p)) < -EPS) q.push_back(p);
	q.push_back(b);
	if(q.size() == 4 && dot((q[0] - q[1]), (q[2] - q[1])) > EPS) swap(q[1], q[2]);
	lf s = 0;
	for(int i = 0; i < q.size() - 1; ++i){
		if(!c.contains(q[i]) || !c.contains(q[i + 1])) s += c.r * c.r * min_angle((q[i] - c.center), q[i+1] - c.center) / 2;
		else s += abs(cross((q[i] - c.center), (q[i + 1] - c.center)) / 2);
	}
	return s;
}

bool circumcircle_contains(vector<pt> tr, pt D) { // triange CCW
  pt A = tr[0] - D, B = tr[1] - D, C = tr[2] - D;

  lf norm_a = norm2(tr[0]) - norm2(D);
  lf norm_b = norm2(tr[1]) - norm2(D);
  lf norm_c = norm2(tr[2]) - norm2(D);

  lf det1 = A.x * (B.y * norm_c - norm_b * C.y);
  lf det2 = B.x * (C.y * norm_a - norm_c * A.y);
  lf det3 = C.x * (A.y * norm_b - norm_a * B.y);

  return det1 + det2 + det3 > E0;
}

// r[k]: area covered by at least k circles
// O(n^2 log n) (high constant)
vector<lf> intercircles(vector<circle> c){
	vector<lf> r(c.size() + 1); 
	for(int i = 0; i < c.size(); ++i){  
		int k = 1;  pt O = c[i].center;
		vector<pair<pt, int>> p = {
			{c[i].center + pt(1,0) * c[i].r, 0},
			{c[i].center - pt(1,0) * c[i].r, 0}};

		for(int j = 0; j < c.size(); ++j) if(j != i){
			bool b0 = c[i].in(c[j]), b1 = c[j].in(c[i]);
			if(b0 && (!b1 || i < j)) ++k;
			else if(!b0 && !b1){
				auto v = inter_cc(c[i], c[j]);
				if(v.size() == 2){
					swap(v[0], v[1]);
					p.push_back({v[0], 1});  
					p.push_back({v[1], -1});
					if(polar_cmp(v[1] - O, v[0] - O)) ++k;
				}
			}
		}

		sort(all(p), [&](auto& a, auto& b){ return polar_cmp(a.first - O, b.first - O); });  
		for(int j = 0; j < p.size(); ++j){
			pt p0 = p[j ? j - 1 : p.size()-1].first, p1 = p[j].first;
			lf a = min_angle((p0 - c[i].center), (p1 - c[i].center));
			r[k] += (p0.x - p1.x) * (p0.y + p1.y) / 2 + c[i].r * c[i].r * (a - sin(a)) / 2;
			k += p[j].second;
		}
	}
	return r;
}
