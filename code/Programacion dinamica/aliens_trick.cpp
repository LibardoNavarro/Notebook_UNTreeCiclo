// We binary search for A and find the highest A such that c(A) ≥ K. 
// Let the optimal value be Aopt. Then our answer is v(Aopt) + AoptK

int main() {
	int n, k;
	cin >> n >> k;

	int a[n];
	for (int &i : a) { cin >> i; }

	/**
	 * the maximum sum along with the number of subarrays used
	 * if creating a subarray penalizes the sum by "lmb" and
	 * there is no limit to the number of subarrays you can create
	 */
	auto solve_lambda = [&](ll lmb) {
		pair<ll, ll> dp[n][2];

		dp[0][0] = {0, 0};
		dp[0][1] = {a[0] - lmb, 1};

		for (int i = 1; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

			dp[i][1] =
			    max(make_pair(dp[i - 1][0].first + a[i] - lmb, dp[i - 1][0].second + 1),
			        make_pair(dp[i - 1][1].first + a[i], dp[i - 1][1].second));
		}

		return max(dp[n - 1][0], dp[n - 1][1]);
	};

	ll lo = 0;
	ll hi = 1e18;
	while (lo < hi) {
		ll mid = (lo + hi + 1) / 2;
		solve_lambda(mid).second >= k ? lo = mid : hi = mid - 1;
	}

	cout << solve_lambda(lo).first + lo * k << endl;
}