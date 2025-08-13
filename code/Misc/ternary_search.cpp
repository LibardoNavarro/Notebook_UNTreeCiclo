// O(log((r-l)/eps))
// returna el maximo valor de f(x) en [l,r]
const double eps = 1e-9;
double f(double x);
double ternary(){
	double l,r;
	while(r-l>eps){
		double m1=l+(r-l)/3.0;
		double m2=r-(r-l)/3.0;
		if(f(m1)<f(m2))l=m1;
		else r=m2;
	}return max(f(l),f(r)); 
}

// ternary search para enteros 
// O(log((r-l)/eps))
// returna el maximo valor de f(x) en [l,r]
int f(int x);
int ternary(){
	int l,r;
	while(r-l>6){
		int m1=l+(r-l)/3;
		int m2=r-(r-l)/3;
		if(f(m1)<f(m2))l=m1; // revisar desempate
		else r=m2;
	}
	int ans=l,val=f(l);
	for(int i=l+1;i<=r;++i){
		int val2=f(i);
		if(val2>val){
			val=val2;
			ans=i;
		}
	}
	return val;
}
