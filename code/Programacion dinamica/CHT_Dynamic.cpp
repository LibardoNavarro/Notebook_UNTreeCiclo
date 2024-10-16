// O((N+Q) log N) <- usando set para add y bs para q
// lineas de la forma mx + b
#pragma once

struct Line {
	mutable ll m, b, p;
	bool operator<(const Line& o) const { return m < o.m; }
	bool operator<(ll x) const { return p < x; }
};

struct CHT : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	static const bool mini = 0; // <---- 1 FOR MIN
	ll div(ll a, ll b){ // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y){
		if (y == end()) return x->p = inf, 0;
		if (x->m == y->m) x->p = x->b > y->b ? inf : -inf;
		else x->p = div(y->b - x->b, x->m - y->m);
		return x->p >= y->p;
	}
	void add(ll m, ll b){
        if (mini){ m *= -1, b *= -1; }
		auto z = insert({m, b, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
        if (mini) return -l.m * x + -l.b;
		else return l.m * x + l.b;
	}
};