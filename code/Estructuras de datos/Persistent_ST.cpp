const ll nullVal = 0;
 
ll oper(ll n1, ll n2){
    return n1 + n2;
}
 
struct Vertex {
    Vertex *l, *r;
    ll val;
 
    Vertex(ll num) : l(nullptr), r(nullptr), val(num) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), val(nullVal) {
        if (l) val = oper(val, l->val);
        if (r) val = oper(val, r->val);
    }
};
 
struct perST{
    ll n;
    // rts es donde guardamos las roots nuevas creadas
    vector<Vertex*> rts;
    
    // Creacion de la root inicial y asignacion de 
    // tamaño de la base de PerST
    perST(vl& a): n(a.size()) { 
        rts.pb(build(a, 0, n - 1)); 
    }
    
    // build del ST (funciona igual que uno normal solo que con punteros)
    Vertex* build(vl& a, ll tl, ll tr) {
        if (tl == tr)
            return new Vertex(a[tl]);
        ll tm = (tl + tr) >> 1;
        return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
    }
 
    // get del ST (funciona igual que uno normal)
    // el valor de tl y tr sirven para saber en que rango nos encontramos
    ll get(Vertex* v, ll tl, ll tr, ll l, ll r) {
        if (l > r)
            return nullVal;
        if (l == tl && tr == r)
            return v-> val;
        ll tm = (tl + tr) >> 1;
        return oper(get(v->l, tl, tm, l, min(r, tm)), 
                    get(v->r, tm+1, tr, max(l, tm+1), r));
    }
    
    // el upd del perST recorre el arbol reciclando nodos que 
    // quedan igual y creando nuevos para los cuales cambia.
    // Retorna el vertice root del nuevo ST
    Vertex* upd(Vertex* v, ll tl, ll tr, ll pos, ll newVal) {
        if (tl == tr)
            return new Vertex(newVal);
        ll tm = (tl + tr) >> 1;
        if (pos <= tm)
            return new Vertex(upd(v->l, tl, tm, pos, newVal), v->r);
        else
            return new Vertex(v->l, upd(v->r, tm+1, tr, pos, newVal));
    }
 
    // simplificaciones de upd y get
    // el valor de k es igual a la version en la cual 
    // trabajaremos
    Vertex* upd(ll k, ll pos, ll newVal){
        return upd(rts[k], 0, n - 1, pos, newVal);
    }
 
    ll get(ll k, ll a, ll b){
        return get(rts[k], 0, n - 1, a, b);
    }
};
