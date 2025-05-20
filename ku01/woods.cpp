#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back


int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, w, L; cin >> n >> w >> L;

  vector<int> h[n];
  for(int i=0; i<n; ++i) {
  	int k; cin >> k;
  	h[i].resize(k); 
  	for(auto &x : h[i]) cin >> x;
  }

	for(int l=0; l<=L; ++l) {
    vector<vector<int>> dp(n, vector<int>(w + 2));
		for(int i=0; i<n; ++i) {
			for(auto x : h[i]) dp[i][max(1,x-l)] ++, dp[i][min(w+1, x+l+1)]--;
		}

		for(int j=1; j<=w; ++j) {
			int c = 0;
			for(int i=0; i<n; ++i) {
				dp[i][j] += dp[i][j-1];
        if(dp[i][j]) c++;
			}

			if(c == n) cout << 1, exit(0);
		}
	}

	cout << 0;
  return 0;
}
