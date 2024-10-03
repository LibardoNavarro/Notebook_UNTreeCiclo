// O(log((r-l)/eps))
double ternary(){
	double l,r;
	while(r-l>eps){
		double m1=l+(r-l)/3.0;
		double m2=r-(r-l)/3.0;
		if(f(m1)<f(m2))l=m1;
		else r=m2;
	}
	return max(f(l),f(r)); 
}
