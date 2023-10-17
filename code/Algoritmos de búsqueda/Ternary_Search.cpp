double f(double x){
  return x*x;
}

// O(log((r-l)/eps))
double ternary_search(double l, double r) {
  double eps=1e-9; // precision
  while(r-l>eps) {
    double m1=l+(r-l)/3;
    double m2=r-(r-l)/3;
    if (f(m1)<f(m2))l=m1;
    else r=m2;
  }return max(f(l),f(r)); // El maximo de la funcion en el intervalo [l,r]
}