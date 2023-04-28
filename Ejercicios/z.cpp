#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> cnt(n + 1);
		int ans = 0;
		for (auto &it : a) {
			cin >> it;
			++cnt[it];
		}
		for (int l = 0; l < n; ++l) {
			int sum = 0;
			for (int r = l; r < n; ++r) {
				sum += a[r];
				if (l == r) continue;
				if (sum <= n) {
					ans += cnt[sum];
					cnt[sum] = 0;
				}
			}
		}
		cout << ans << endl;
	}
}