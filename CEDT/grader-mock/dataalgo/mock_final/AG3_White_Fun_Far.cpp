#include <bits/stdc++.h>
using namespace std;
const int mod = 1e8 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<int>> state = {{1, 3}, {2}, {0}, {0, 1}};
  vector<int> dp(4);
  for (int i = 0; i < 4; ++i) dp[i] = 1;

  for (int i = 2; i <= n; ++i) {
    vector<int> nxt(4);
    for (int j = 0; j < 4; ++j) {
      for (auto &y : state[j]) {
        nxt[j] += dp[y];
        nxt[j] %= mod;
      }
    }
    for (int j = 0; j < 4; ++j) dp[j] = nxt[j];
  }

  int res = 0;
  for (int i = 0; i < 4; ++i) res += dp[i], res %= mod;
  cout << res;
  return 0;
}
