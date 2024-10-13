// Maximizar c1*x1 + c2*x2 + c3*x3 ...
// Restricciones a11*x1 + a12*x2 <= b1, a22*x2 + a23*x3 <= b2 ...
// Retorna valor optimo y valores de las variables

// O(c^2*b), O(c*b) - variables c, restricciones b
struct Simplex{
	vector<vector<double>> A;
	vector<double> B,C;
	vector<int> X,Y;
	double z;
	int n,m;

	Simplex(vector<vector<double>> _a, vector<double> _b, vector<double> _c){
		A=_a;B=_b;C=_c;
		n=B.size();m=C.size();z=0.;
		X=vector<int>(m);Y=vector<int>(n);
		for(int i=0;i<m;++i)X[i]=i;
		for(int i=0;i<n;++i)Y[i]=i+m;
	}

	void pivot(int x,int y){
		swap(X[y],Y[x]);
		B[x]/=A[x][y];
		for(int i=0;i<m;++i)if(i!=y)A[x][i]/=A[x][y];
		A[x][y]=1/A[x][y];
		for(int i=0;i<n;++i)if(i!=x&&abs(A[i][y])>EPS){
			B[i]-=A[i][y]*B[x];
			for(int j=0;j<m;++j)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
			A[i][y]=-A[i][y]*A[x][y];
		}
		z+=C[y]*B[x];
		for(int i=0;i<m;++i)if(i!=y)C[i]-=C[y]*A[x][i];
		C[y]=-C[y]*A[x][y];
	}
	
	pair<double, vector<double>> maximize(){
		while(1){
			int x=-1,y=-1;
			double mn=-EPS;
			for(int i=0;i<n;++i)if(B[i]<mn)mn=B[i],x=i;
			if(x<0)break;
			for(int i=0;i<m;++i)if(A[x][i]<-EPS){y=i;break;}
			// y<0, no solution to Ax<=B
			pivot(x,y);
		}
		while(1){
			double mx=EPS;
			int x=-1,y=-1;
			for(int i=0;i<m;++i)if(C[i]>mx)mx=C[i],y=i;
			if(y<0)break;
			double mn=1e200;
			for(int i=0;i<n;++i)if(A[i][y]>EPS&&B[i]/A[i][y]<mn)mn=B[i]/A[i][y],x=i;
			// x<0, unbounded
			pivot(x,y);
		}
		vector<double> r(m);
		for(int i=0;i<n;++i)if(Y[i]<m)r[Y[i]]=B[i];
		return {z,r};
	}
};
