typedef long double lf;
const lf EPS = 1e-9; 
const lf E0 = 0.0L; //Keep = 0 for integer coordinates, otherwise = EPS
const lf PI = acos(-1);

struct pt {
    lf x, y;   
    pt(){}
    pt(lf a, lf b): x(a), y(b){}
    pt operator - (const pt &q) const { return {x - q.x , y - q.y }; }
    pt operator + (const pt &q) const { return {x + q.x , y + q.y }; }
    pt operator * (const lf &t) const { return {x * t , y * t }; }
    pt operator / (const lf &t) const { return {x / t , y / t }; }
    bool operator == (pt p){ return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS; }
    bool operator != (pt p){ return !operator==(p); }
    bool operator < (const pt & q) const {
        if(fabsl(x - q.x) > E0) return x < q.x;
        return y < q.y;
    }
    void print(){ cout << x << " " << y << "\n"; } 
};

pt normalize(pt p){
    lf norm = hypotl(p.x, p.y);
    if(fabsl(norm) > EPS) return {p.x /= norm, p.y /= norm};
    else return p;
}

int cmp(lf a, lf b){ return (a + EPS < b ? -1 :(b + EPS < a ? 1 : 0)); } // float comparator

// rota ccw
pt rot90(pt p){ return {-p.y, p.x}; }
// w(RAD)
pt rot(pt p, lf w){ return {cosl(w) * p.x - sinl(w) * p.y, sinl(w) * p.x + cosl(w) * p.y}; }

lf norm2(pt p){ return p.x * p.x + p.y * p.y; }
lf norm(pt p){ return hypotl(p.x, p.y); }

lf dis2(pt p, pt q){ return norm2(p - q); }
lf dis(pt p, pt q){ return norm(p - q); }

lf arg(pt a){return atan2(a.y, a.x); } // ang(RAD) a x-pos
lf dot(pt a, pt b){ return a.x * b.x + a.y * b.y; } // x = 90 -> cos = 0
lf cross(pt a, pt b){ return a.x * b.y - a.y * b.x; } // x = 180 -> sin = 0
lf orient(pt a, pt b, pt c){ return cross(b - a, c - a); } // clockwise = -
int sign(lf x){ return (lf(0) < x) - (x < lf(0)); }

// x inside angle abc (center in a)
bool in_angle(pt a, pt b, pt c, pt p) {
    //assert(fabsl(orient(a, b, c)) > E0);
    if(orient(a, b, c) < -E0)
        return orient(a, b, p) >= -E0 || orient(a, c, p) <= E0;
    return orient(a, b, p) >= -E0 && orient(a, c, p) <= E0;
}

// lf angle(pt a, pt b){ return acos(max((lf)-1.0, min((lf)1.0, dot(a, b)/norm(a)/norm(b)))); } // min ang(RAD)
lf angle(pt a, pt b){ return atan2(cross(a, b), dot(a, b)); } // ang(RAD)
lf angle(pt a, pt b, pt c){ // ang(RAD) AB AC ccw
    lf ang = angle(b - a, c - a);
    if (ang < 0) ang += 2 * PI;
    return ang;
} 

bool half(pt p){ // true if is in (0, 180] (line is x axis)
    // assert(p.x != 0 || p.y != 0); // the argument of (0, 0) is undefined
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

bool half_from(pt p, pt v = {1, 0}) {
  return cross(v,p) < 0 || (cross(v,p) == 0 && dot(v,p) < 0);
}

// polar sort
bool polar_cmp(const pt &a, const pt &b){
  return make_tuple(half(a), 0) < make_tuple(half(b), cross(a,b));
}

void polar_sort(vector<pt> &v, pt o){ // sort points in counterclockwise with respect to point o
    sort(v.begin(), v.end(), [&](pt a,pt b) {
        return make_tuple(half(a - o), 0.0, norm2((a - o))) < make_tuple(half(b - o), cross(a - o, b - o), norm2((b - o)));
    });
}
