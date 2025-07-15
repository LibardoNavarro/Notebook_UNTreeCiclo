// O(n*log(log(n)))
vector<ll> primes;
vector<bool> is_prime;
void criba(ll n){
	is_prime.assign(n+1,true);
	for(ll i=2;i<=n;++i){
		if(!is_prime[i])continue;
		for(ll j=i*i;j<=n;j+=i)is_prime[j]=false;
		primes.push_back(i);
	}
}

// O(sqrt(n)/log(sqrt(n)))
void fact(ll n, map<ll, int>& f){
	for(int i=0;i<sz(primes) && primes[i]*primes[i]<=n;++i) 
		while(n%primes[i]==0ll)f[primes[i]]++,n/=primes[i];
	if(n>1)f[n]++;
}
