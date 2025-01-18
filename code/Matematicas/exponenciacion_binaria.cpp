ll binpow(ll b, ll n, ll m) {
	b %= m;
	ll res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * b % m;
		b = b * b % m;
		n >>= 1;
	}
	return res % m;
}