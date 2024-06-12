// O(s+t)
// Dado un patrón s y un texto t, devuelve un vector con las posiciones de las ocurrencias de s en t
vi rabin_karp(string const& s, string const& t) {
	// Ojo con p y m
	const int p=31; 
	const int m=1e9+9;
	int S=s.size(),T=t.size();
	vl p_pow(max(S, T)); 
	p_pow[0]=1; 
	// Precalculo de potencias de p
	for(int i=1;i<sz(p_pow);i++)p_pow[i]=(p_pow[i-1]*p)%m;
	vl h(T+1,0); 
	// Precalculo de hashes de prefijos de t
	for(int i=0;i<T;i++)h[i+1]=(h[i]+(t[i]-'a'+1)*p_pow[i])%m; 
	ll h_s=0; 
	// Hash de s
	for(int i=0;i<S;i++)h_s=(h_s+(s[i]-'a'+1)*p_pow[i])%m; 
	vi occurrences;
	for(int i=0;i+S-1<T;i++) {
		ll cur_h=(h[i+S]+m-h[i])%m;
		if(cur_h==h_s*p_pow[i]%m)occurrences.push_back(i);
	}
	return occurrences;
}