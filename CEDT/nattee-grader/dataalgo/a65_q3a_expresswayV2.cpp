#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back
const int N = 703;
ll dp[N][N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) dp[i][j] = INT_MAX;
    dp[i][i] = 0;
  }
  dp[0][1] = dp[1][0] = k;

  for(int k=2; k<n; ++k) {
    int t; cin >> t;
    while(t --) {
      int u, w; cin >> u >> w; u--;
      dp[k][u] = dp[u][k] = w;
    }
  }

  for(int k=2; k<n; ++k) {
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        if(dp[i][k] == INT_MAX or dp[k][j] == INT_MAX) continue ;
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
    cout << dp[0][1] << ' ';
  }
  return 0;
}
