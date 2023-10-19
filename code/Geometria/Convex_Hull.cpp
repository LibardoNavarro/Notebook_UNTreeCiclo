struct pt{
    double x,y;
    int type;
    pt(double x,double y,int t): x(x),y(y),type(t){}
};
 
// Devuelve hacia donde esta un punto c, respecto una linea ab
int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // en la derecha
    if (v > 0) return +1; // en la izquierda
    return 0; // colinear
}
 
// imprime verdadero el punto c, esta a la derecha de la linea pb,
// tambien da true si son cololineales e include_collinear == true 
bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
 
// nos dice si tres puntos son colineales
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }
 
void convex_hull(vector<pt>& a, bool include_collinear = false) {
 
    // Obtenemos el pivote como el menor punto con un criterio dado 
    // (menor y o si no menor x)
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
 
    // Ordenamos los puntos en un orden horario, los elementos colineales terminan
    // siendo arrastrados al final y si existe empate en el angulo sera el que este mas cerca
    // del pivote
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
 
    // Busca donde empiezan los colineales (estan al final) e invierte su orden
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }
    
    // Aplicacion de graham
    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }
 
    a = st;
}