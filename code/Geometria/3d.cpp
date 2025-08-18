typedef double lf;
struct p3 {
    lf x, y, z;
	p3(){}
	p3(lf x, lf y, lf z): x(x), y(y), z(z){}
    p3 operator + (p3 p){ return {x + p.x, y + p.y, z + p.z}; }
    p3 operator - (p3 p){ return {x - p.x, y - p.y, z - p.z}; }
    p3 operator * (lf d){ return {x * d, y * d, z * d}; }
    p3 operator / (lf d){ return {x / d, y / d, z / d}; } // only for floating point
    // Some comparators
    bool operator == (p3 p){ return tie(x, y, z) == tie(p.x, p.y, p.z); }
    bool operator != (p3 p){ return !operator == (p); }
	void print(){ cout << x << " " << y << " " << z << "\n"; }
	// scale: (newnorm / norm) * p3
};

lf dot(p3 v, p3 w){ return v.x * w.x + v.y * w.y + v.z * w.z; }

p3 cross(p3 v, p3 w){
    return { v.y * w.z - v.z * w.y, v.z * w.x - v.x * w.z, v.x * w.y - v.y * w.x };
}

lf norm2(p3 v){ return dot(v, v); }
lf norm(p3 v){ return sqrt(norm2(v)); }
p3 unit(p3 v){ return v / norm(v); }

// ang(RAD)
double angle(p3 v, p3 w){
    double cos_theta = dot(v, w) / norm(v) / norm(w);
    return acos(max(-1.0, min(1.0, cos_theta)));
}

// orient s, pqr form a triangle pos: 'up', zero = on, neg = 'dow'
lf orient(p3 p, p3 q, p3 r, p3 s){ 
  	return dot(cross((q - p), (r - p)), (s - p));
}

// same as 2D but in n-normal direction
lf orient_by_normal(p3 p, p3 q, p3 r, p3 n){
  	return dot(cross((q - p), (r - p)), n);
}

struct plane {
    p3 n; lf d; // n: normal d: dist to zero
    // From normal n and offset d
    plane(p3 n, lf d): n(n), d(d) {}
    // From normal n and point P
    plane(p3 n, p3 p): n(n), d(dot(n, p)) {}
    // From three non-collinear points P,Q,R
    plane(p3 p, p3 q, p3 r): plane(cross((q - p), (r - p)), p){}
    // - these work with lf = int
    lf side(p3 p) { return dot(n, p) - d; }
    double dist(p3 p) { return abs(side(p)) / norm(n); }
    plane translate(p3 t) {return {n, d + dot(n, t)}; }
    /// - these require lf = double
    plane shift_up(double dist){ return {n, d + dist * norm(n)}; }
    p3 proj(p3 p){ return p - n * side(p) / norm2(n); }
    p3 refl(p3 p){ return p - n * 2 * side(p) / norm2(n); }
};

struct line3d {
	p3 d, o; // d: dir o: point on line
	// From two points P, Q
	line3d(p3 p, p3 q): d(q - p), o(p){}
	// From two planes p1, p2 (requires lf = double)
	line3d(plane p1, plane p2){
		d = cross(p1.n, p2.n);
		o = cross((p2.n * p1.d - p1.n * p2.d), d) / norm2(d);
	}
	// - these work with lf = int
	double dist2(p3 p){ return norm2(cross(d, (p - o))) / norm2(d); }
	double dist(p3 p){ return sqrt(dist2(p)); }
	bool cmp_proj(p3 p, p3 q){ return dot(d, p) < dot(d, q); }
	// - these require lf = double
	p3 proj(p3 p){ return o + d * dot(d, (p - o)) / norm2(d); }
	p3 refl(p3 p){ return proj(p) * 2 - p; }
	p3 inter(plane p){ return o - d * p.side(o) / dot(p.n, d); }
	// get other point: pl.o + pl.d * t;
};

double dist(line3d l1, line3d l2) {
	p3 n = cross(l1.d, l2.d);
	if(n == p3(0, 0, 0)) return l1.dist(l2.o); // parallel
	return abs(dot((l2.o - l1.o), n)) / norm(n);
}

// closest point on l1 to l2
p3 closest_on_line1(line3d l1, line3d l2) { 
	p3 n2 = cross(l2.d, cross(l1.d, l2.d));
	return l1.o + l1.d * (dot((l2.o - l1.o), n2)) / dot(l1.d, n2);
}

double small_angle(p3 v, p3 w){ return acos(min(abs(dot(v, w)) / norm(v) / norm(w), 1.0)); } // 0 90
double angle(plane p1, plane p2){ return small_angle(p1.n, p2.n); }
bool is_parallel(plane p1, plane p2){ return cross(p1.n, p2.n) == p3(0, 0, 0); }
bool is_perpendicular(plane p1, plane p2){ return dot(p1.n, p2.n) == 0; }
double angle(line3d l1, line3d l2){ return small_angle(l1.d, l2.d); }
bool is_parallel(line3d l1, line3d l2){ return cross(l1.d, l2.d) == p3(0, 0, 0); }
bool is_perpendicular(line3d l1, line3d l2){ return dot(l1.d, l2.d) == 0; }
double angle(plane p, line3d l){ return M_PI / 2 - small_angle(p.n, l.d); }
bool is_parallel(plane p, line3d l){ return dot(p.n, l.d) == 0; }
bool is_perpendicular(plane p, line3d l){ return cross(p.n, l.d) == p3(0, 0, 0); }
line3d perp_through(plane p, p3 o){ return line3d(o, o + p.n); }
plane perp_through(line3d l, p3 o){ return plane(l.d, o); }

pair<p3, lf> smallest_enclosing_sphere(vector<p3> p) {
    int n = p.size();
    p3 c(0, 0, 0);
    for(int i = 0; i < n; i++) c = c + p[i];
    c = c / n;

    double ratio = 0.1;
    int pos = 0;
    int it = 100000;
    while (it--) {
        pos = 0;
        for (int i = 1; i < n; i++) {
            if(norm2(c - p[i]) > norm2(c - p[pos])) pos = i;
        }
        c = c + (p[pos] - c) * ratio;
        ratio *= 0.998;
    }
    return {c, sqrt(norm2(c - p[pos]))};
}