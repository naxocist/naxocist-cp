#include <bits/stdc++.h>
using namespace std;

const int N = 503;
double p[N][N];
double dp[N][N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> dp[i][j];
      dp[i][j] = log(1.0 / dp[i][j]);
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dp[i][k] + dp[k][j] < dp[i][j])
          dp[i][j] = dp[i][k] + dp[k][j];
      }
    }
  }

  bool neg_cycle = false;
  for (int k = 0; k < n; ++k) {
    if(dp[k][k] < 0) neg_cycle = true;
  }

  cout << (neg_cycle ? "YES" : "NO") << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
