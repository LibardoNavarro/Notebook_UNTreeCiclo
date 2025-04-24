// d(n) = (a1+1)*(a2+1)*...*(ak+1)
ll numDiv(map<ll, ll>& f){
	ll ans=1;
	for(auto [_,pot]:f)ans=mul(ans, (pot+1ll));
	return ans;
}

// sigma(n) = (p1^(a1+1)-1)/(p1-1) * (p2^(a2+1)-1)/(p2-1) * ... * (pk^(ak+1)-1)/(pk-1)
// suma divisores a la xth potencia
ll sumDiv(map<ll, ll>& f){
	ll ans=1,potencia=1;         
	for(auto [num, pot]:f){
		ll p=binpow(num,(pot+1ll)*potencia)-1ll;
		ans=mul(ans, mul(p, inv(num-1ll)));
	}
	return ans;
}

ll productDiv(map<ll, ll>& f){
	ll pi=1,res=1;
	for(auto [num, pot]:f){
		ll p=binpow(num, pot*(pot+1ll)/2ll);
		res=mul(binpow(res, pot+1ll),binpow(p, pi));
		pi=mul(pi, pot+1ll, MOD-1ll);
	}
	return res;
}

// si a y b son coprimos, entonces: 
// sigma(a*b) = sigma(a)*sigma(b)
// d(a*b) = d(a)*d(b)
