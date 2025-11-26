#include <bits/stdc++.h>
using namespace std;

const int N = 103;
int dp[N], t[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  int mx = INT_MIN;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=i; ++j) {
      int x; cin >> x;
      t[j] = max(dp[j], dp[j-1]) + x;
    }
    for(int j=1; j<=i; ++j) dp[j] = t[j], mx = max(mx, dp[j]);
  }
  cout << mx << '\n';
  return 0;
}
