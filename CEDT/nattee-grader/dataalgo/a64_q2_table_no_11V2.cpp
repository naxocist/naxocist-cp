#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int mod = 1e8 + 7;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  int s = 1;
  for(int i=1; i<=n; ++i) {
    dp[i] = dp[i-1] + 2*s; dp[i] %= mod;
    s += dp[i-1]; s %= mod;
  }
  cout << dp[n];
  return 0;
}
