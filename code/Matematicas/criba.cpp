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

// O((R-L+1)log(log(R))+sqrt(R)log(log(sqrt(R)))
// R-L+1 <= 1e7, R <= 1e14
void segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R)+3;
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
}