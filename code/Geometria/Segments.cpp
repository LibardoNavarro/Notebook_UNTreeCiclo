// add Lines Points

bool in_disk(pt a, pt b, pt p){ // pt p inside ab disk
    return dot(a - p, b - p) <= E0;
}

bool on_segment(pt a, pt b, pt p) { // p on ab
    return orient(a, b, p) == 0 && in_disk(a, b, p);
}

// ab crossing cd
bool proper_inter(pt a, pt b, pt c, pt d, pt& out) {
    lf oa = orient(c, d, a);
    lf ob = orient(c, d, b);
    lf oc = orient(a, b, c);
    lf od = orient(a, b, d);
    // Proper intersection exists iff opposite signs
    if (oa * ob < 0 && oc * od < 0) {
        out = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}

// intersection bwn segments
set<pt> inter_ss(pt a, pt b, pt c, pt d) {
    pt out;
    if (proper_inter(a, b, c, d, out)) return {out}; // if cross -> 1
    set<pt> s;
    if (on_segment(c, d, a)) s.insert(a); // a in cd
    if (on_segment(c, d, b)) s.insert(b); // b in cd
    if (on_segment(a, b, c)) s.insert(c); // c in ab
    if (on_segment(a, b, d)) s.insert(d); // d in ab
    return s; // 0, 2
}

lf pt_to_seg(pt a, pt b, pt p) { // p to ab
    if (a != b) {
        line l(a, b);
        if (l.cmp_proj(a, p) && l.cmp_proj(p, b)) // if closest to projection = (a, p, b)
            return l.dist(p); // output distance to line
    }
    return min(norm(p - a), norm(p - b)); // otherwise distance to A or B
}

lf seg_to_seg(pt a, pt b, pt c, pt d) {
    pt dummy;
    if (proper_inter(a, b, c, d, dummy)) return 0; // ab intersects cd
    return min({pt_to_seg(a, b, c), pt_to_seg(a, b, d), pt_to_seg(c, d, a), pt_to_seg(c, d, b)}); // try the 4 pts
}

int length_union(vector<pt>& a){ // REVISAR
    int n = a.size();
    vector<pair<int, bool>> x(n * 2);
    for (int i = 0; i < n; i++) {
        x[i * 2] = {a[i].x, false};
        x[i * 2 + 1] = {a[i].y, true};
    }
    sort(x.begin(), x.end());
    int result = 0;
    int c = 0;
    for (int i = 0; i < n * 2; i++) {
        if (i > 0 && x[i].first > x[i - 1].first && c > 0) result += x[i].first - x[i - 1].first;
        if (x[i].second) c--;
        else c++;
    }
    return result;
}