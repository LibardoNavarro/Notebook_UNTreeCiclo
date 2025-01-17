// O(n), par (raiz, izq, der) 1 - impar 0
vector<int> manacher(string& s, int par){ 
	int l=0,r=-1,n=sz(s);
	vector<int> m(n,0);
	for(int i=0;i<n;++i){
		int k=(i>r?(1-par):min(m[l+r-i+ par], r-i+par))+par;
		while(i+k-par<n && i-k>=0 && s[i+k-par]==s[i-k])++k;
		m[i]=k-par;--k;
		if(i+k-par>r)l=i-k,r=i+k-par;
	}
	for(int i=0;i<n;++i)m[i]=(m[i]-1+par)*2+1-par;
	return m;
}
