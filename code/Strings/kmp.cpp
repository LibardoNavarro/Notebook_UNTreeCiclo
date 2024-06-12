// O(t+p)
int matches=0;
void kmp(string& t, string& p){ 
	vi phi=prefix_function(p);
	for(int i=0,j=0;i<sz(t);i++){
		while(j>0 && t[i]!=p[j])j=phi[j-1];
		if(t[i]==p[j])j++;
		if(j==sz(p)){
			cout<<i-j+1<<" "; // Posición de la ocurrencia
			matches++;
			j=phi[j-1];
		}
	}
}

// Devuelve el arreglo de matches
const int MAX=2e5+9;
int pi[MAX];
// Pasar d el arreglo
void kmp_vi(string& t, string& s, int *d){
	pi[0]=0;int m=sz(t),n=sz(s);
	for(int i=1,k=0;i<m;i++){
		while(k>0 && t[k]!=t[i])k=pi[k-1];
		if(t[i]==t[k])k++;
		pi[i]=k;
	}
	for(int i=0,k=0;i<n;i++){
		while(k>0 && t[k]!=s[i])k=pi[k-1];
		if(s[i]==t[k])k++;
		d[i]=k;
		if(k==m)k=pi[k-1];
	}
}