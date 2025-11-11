#include <bits/stdc++.h>
using namespace std;

const int N = 503;
int dp[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string a, b; cin >> a >> b;
  int n = a.size(), m = b.size();
  a = '.' + a, b = '.' + b;

  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      if(a[i] == b[j]) {
        dp[i][j] = dp[i-1][j-1] + 1;
        continue ;
      }

      dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
    }
  }

  cout << dp[n][m] << '\n';

  return 0;
}
