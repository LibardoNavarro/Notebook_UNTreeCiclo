#include <bits/stdc++.h>
using namespace std;
using double = long long;

int n;
double weight[20];

double solve(int i, double sum1, double sum2) {
	if (i == n) { return abs(sum1 - sum2); }
	return min(solve(i + 1, sum1 + weight[i], sum2),
	           solve(i + 1, sum1, sum2 + weight[i]));
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> weight[i]; }
	cout << solve(0, 0, 0) << endl;
}
