#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  int dp[722] = {};
  while(n--) {
    int a, b; cin >> a >> b; a++, b++;
    if(a < b) dp[a]++, dp[b+1]--;
    else dp[a]++, dp[b+361]--;
  }

  int res = 0, c = 0;
  for(int i=1; i<722; ++i) {
    dp[i] += dp[i-1];
    if(dp[i] > 0) c++, res = max(res, c-1);
    else c=0;
  }

  cout << min(res, 360);
  return 0;
}
