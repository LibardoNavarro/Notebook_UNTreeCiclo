// O(log n) muy rapido
// F(2n+1) = F(n)^2 + F(n+1)^2
// F(2n) = F(n+1)^2 - F(n-1)^2
pair<int, int> fib (int n) {
	if (n == 0)
		return {0, 1};

	auto p = fib(n >> 1);
	int c = p.first * (2 * p.second - p.first);
	int d = p.first * p.first + p.second * p.second;
	if (n & 1)
		return {d, c + d};
	else
		return {c, d};
}