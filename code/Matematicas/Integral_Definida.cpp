const int steps = 1e6; // %2==0
double f(double x);
double simpson(double a, double b){
	double h=(b-a)/steps;
	double s=f(a)+f(b);
	for(int i=1;i<=steps-1;i++){ 
		double x=a+h*i;
		s+=f(x)*((i&1)?4:2);
	}
	s*=h/3;
	return s;
}