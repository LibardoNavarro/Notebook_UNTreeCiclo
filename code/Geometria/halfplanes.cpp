const lf INF = 1e100;
struct Halfplane {
    pt p, pq; // p: point on line, pq: dir, take left 
    lf angle;
    Halfplane(){}
    Halfplane(pt& a, pt& b): p(a), pq(b - a){
        angle = atan2l(pq.y, pq.x);
    }

    bool out(const pt& r){ return cross(pq, r - p) < -EPS;} // checks if p is inside the half plane
    bool operator < (const Halfplane& e) const { return angle < e.angle; }

};

// intersection pt of the lines of 2 halfplanes
pt inter(const Halfplane& s, const Halfplane& t){
    if (abs(cross(s.pq, t.pq)) <= EPS) return {INF, INF};
    lf alpha = cross((t.p - s.p), t.pq) / cross(s.pq, t.pq);
    return s.p + (s.pq * alpha);
}

// O(nlogn) return CCW polygon
vector<pt> hp_intersect(vector<Halfplane>& H) {
    pt box[4] = {pt(INF, INF), pt(-INF, INF), pt(-INF, -INF), pt(INF, -INF)};

    for(int i = 0; i < 4; ++i ) {
        Halfplane aux(box[i], box[(i + 1) % 4]);
        H.push_back(aux);
    }

    sort(H.begin(), H.end());
    deque<Halfplane> dq;
    int len = 0;
    for(int i = 0; i < int(H.size()); ++i){

        while (len > 1 && H[i].out(inter(dq[len - 1], dq[len - 2]))){
            dq.pop_back();
            --len;
        }

        while (len > 1 && H[i].out(inter(dq[0], dq[1]))){
            dq.pop_front();
            --len;
        }

        if (len > 0 && fabsl(cross(H[i].pq, dq[len - 1].pq)) < EPS){
            if (dot(H[i].pq, dq[len - 1].pq) < 0.0) return vector<pt>();

            if (H[i].out(dq[len - 1].p)){
                dq.pop_back();
                --len;
            } else continue;
        }

        dq.push_back(H[i]);
        ++len;
    }

    while (len > 2 && dq[0].out(inter(dq[len - 1], dq[len - 2]))){
        dq.pop_back();
        --len;
    }

    while (len > 2 && dq[len - 1].out(inter(dq[0], dq[1]))){
        dq.pop_front();
        --len;
    }

    if (len < 3) return vector<pt>();

    vector<pt> ret(len);
    for(int i = 0; i + 1 < len; ++i) ret[i] = inter(dq[i], dq[i + 1]);
    
    ret.back() = inter(dq[len - 1], dq[0]);
    // remove repeated points if needed
    return ret;
}


// ----------------------------------------------------

// intersection of halfplanes
vector<pt> hp_intersect(vector<halfplane>& b){
    vector<pt> box = {{inf, inf}, {-inf, inf}, {-inf, -inf}, {inf, -inf}};
    for(int i = 0; i < 4; i++){
        b.push_back({box[i], box[(i + 1) % 4]});
    }
    sort(b.begin(), b.end());
    int n = b.size(), q = 1, h = 0;
    vector<halfplane> c(n + 10);
    for(int i = 0; i < n; i++){
        while(q < h && b[i].out(inter(c[h], c[h - 1]))) h--;
        while(q < h && b[i].out(inter(c[q], c[q + 1]))) q++;
        c[++h] = b[i];
        if(q < h && abs(cross(c[h].pq, c[h-1].pq)) < EPS){
            if(dot(c[h].pq, c[h - 1].pq) <= 0) return {};
            h--;
            if(b[i].out(c[h].p)) c[h] = b[i];
        }
    }
    while(q < h - 1 && c[q].out(inter(c[h], c[h - 1]))) h--;
    while(q < h - 1 && c[h].out(inter(c[q], c[q + 1]))) q++;
    if(h - q <= 1) return {};
    c[h + 1] = c[q];
    vector<pt> s;
    for(int i = q; i < h + 1; i++) s.pb(inter(c[i], c[i + 1]));
    return s;
}