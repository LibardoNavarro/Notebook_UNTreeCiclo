// add points operators
struct line {
	pt v; lf c; // v: dir, c: mov y, cross(v, p) = c
	line(pt v, lf c) : v(v), c(c) {}
	line(lf a, lf b, lf c) : v({b, -a}), c(c) {} // ax + by = c
	line(pt p, pt q) : v(q - p), c(cross(v, p)) {}
	line(lf m, lf b): v({1, m}), c(b) {} 
	
	bool operator < (line l){ return cross(v, l.v) > 0; } 
	bool operator == (line l){ return (abs(cross(v, l.v)) <= E0) && c == l.c; } // abs(c) == abs(l.c)

	lf side(pt p){ return cross(v, p) - c; }
	lf dist(pt p){ return abs(side(p)) / norm(v); }
	lf dist2(pt p){ return side(p) * side(p) / (lf)norm2(v); }
	line perp_through(pt p){ return {p, p + rot90(v)}; } // line perp to v passing through p
	bool cmp_proj(pt p, pt q){ return dot(v, p) < dot(v, q); } // order for points over the line
	// use: auto fsort = [&l1](const pt &a, const pt &b){ return l1.cmp_proj(a, b); };
	line translate(pt t){ return {v, c + cross(v, t)}; }
	line shift_left(lf d){ return {v, c + d*norm(v)}; }
	pt proj(pt p){ return p - rot90(v) * side(p) / norm2(v); } // pt proyected on the line
	pt refl(pt p){ return p - rot90(v) * 2 * side(p) / norm2(v); } // pt reflected on the other side of the line
	bool has(pt p){ return abs(cross(v, p) - c) <= E0; }; // pt on line
	
	lf evalx(lf x){
		assert(fabsl(v.x) > EPS);
		return (c + v.y * x) / v.x;
	}

};

pt inter_ll(line l1, line l2) {
	if (abs(cross(l1.v, l2.v)) <= EPS) return {INF, INF}; // parallel
	return (l2.v * l1.c - l1.v * l2.c) / cross(l1.v, l2.v); // floating points
}

// bisector divides the angle in 2 equal angles
// interior line goes on the same direction as l1 and l2
line bisector(line l1, line l2, bool interior) {
	// assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel
	lf sign = interior ? 1 : -1;
	return {l2.v / norm(l2.v) + l1.v / norm(l1.v) * sign,
			l2.c / norm(l2.v) + l1.c / norm(l1.v) * sign};
}