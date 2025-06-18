#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n; vector<ll> v(n + 1); for(int i=1; i<=n; ++i) cin >> v[i];

	vector<ll> dp(n + 1); dp[1] = v[1];
	for(int i=2; i<n; ++i) {
		dp[i] = max(dp[i-1], dp[i-2] + v[i]);
	}

	ll res = dp[n-1];

	fill(dp.begin(), dp.end(), 0);
	for(int i=2; i<=n; ++i) {
		dp[i] = max(dp[i-1], dp[i-2] + v[i]);
	}

	cout << max(res, dp[n]);
	
	return 0;
}
