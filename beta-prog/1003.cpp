#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n; cin >> n;
  vector<bool> dp(n + 1); dp[0] = 1;
  bool ok = 0;
  for(int i=6; i<=n; ++i) {
    dp[i] = dp[i-6] or (i>=9 ? dp[i-9] : 0) or (i>=20 ? dp[i-20] : 0);

    if(dp[i]) cout << i << '\n', ok = 1;
  }

  if(!ok) cout << "no";
  return 0;
}
