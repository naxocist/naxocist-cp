#include <bits/stdc++.h>
using namespace std;


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b, c; cin >> n >> a >> b >> c;
  vector<int> dp(n + 1);
  for(int i=1; i<=n; ++i) {
    dp[i] = -2e9;
    if(i-a>=0) dp[i] = dp[i-a];
    if(i-b>=0) dp[i] = max(dp[i],dp[i-b]);
    if(i-c>=0) dp[i] = max(dp[i],dp[i-c]);
    dp[i] ++;
  }
  cout << dp[n];
  return 0;
}
