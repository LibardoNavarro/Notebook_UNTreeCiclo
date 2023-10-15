// Implementar primero prefix_function
// O(t+p)
int matches=0;
void kmp(string &t, string &p){ 
  vi phi=prefix_function(p);
  for(int i=0,j=0;i<sz(t);i++){
    while(j>0 && t[i]!=p[j])j=phi[j-1];
    if(t[i]==p[j])j++;
    if(j==sz(p)){
      cout<<i-j+1<<" "; // Posicion de la ocurrencia
      matches++;
      j=phi[j-1];
    }
  }
}

// Devuelve el arreglo de matches sin implementar prefix_function
const int MAX=2e5+9;
int pi[MAX];
// Pasar el arreglo int d con tamano len(t)
void kmp_vi(string& p, string& t, int *d){
	pi[0]=0;int m=len(p),n=len(t);
	for(int i=1,k=0;i<m;i++){
		while(k>0 && p[k]!=p[i])k=pi[k-1];
		if(p[i]==p[k])k++;
		pi[i]=k;
	}
	for(int i=0,k=0;i<n;i++){
		while(k>0 && p[k]!=t[i])k=pi[k-1];
		if(t[i]==p[k])k++;
		d[i]=k;
		if(k==m)k=pi[k-1];
	}
}
