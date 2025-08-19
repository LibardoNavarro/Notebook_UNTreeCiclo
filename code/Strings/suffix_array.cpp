// O(n*log(n)) - char in [1, lim)
// sa: is the starting position of the i-th lex smallest suffix
// rnk: is the rank (position in SA) of the suffix starting at i
// lcp: is the longest common prefix between sa[i] and sa[i+1]
auto SuffixArray(string s, int lim=256) { 
	s.push_back(0); int n = sz(s), k = 0, a, b;
	vi sa, lcp, rnk(all(s)), y(n), ws(max(n, lim));
	sa = lcp = y, iota(all(sa), 0);
	for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
		p = j, iota(all(y), n - j);
		rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
		fill(all(ws), 0);
		rep(i,0,n) ws[rnk[i]]++;
		rep(i,1,lim) ws[i] += ws[i - 1];
		for (int i = n; i--;) sa[--ws[rnk[y[i]]]] = y[i];
		swap(rnk, y), p = 1, rnk[sa[0]] = 0;
		rep(i,1,n) a = sa[i - 1], b = sa[i], rnk[b] =
			(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
	}
	for (int i = 0, j; i < n - 1; lcp[rnk[i++]] = k)
		for (k && k--, j = sa[rnk[i] - 1]; s[i + k] == s[j + k]; k++);
	reverse(all(lcp));lcp.pop_back();reverse(all(lcp));
	return tuple{sa, rnk, lcp};
}