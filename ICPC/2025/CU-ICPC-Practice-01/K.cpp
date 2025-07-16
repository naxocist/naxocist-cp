#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;

  unordered_map<ll, ll> um;
  ll mx = 0;
  vector<ll> v(n); for(auto &x : v) cin >> x, um[x] ++, mx = max(mx, x);

  vector<ll> dp(mx + 1);
  for(int i=1; i<=mx; ++i) {
    if(um[i] == 0) dp[i] = dp[i-1];
    else dp[i] = max(i*um[i] + dp[max(0, i-2)], dp[i-1]);
  }

  cout << dp[mx];
  return 0;
}
