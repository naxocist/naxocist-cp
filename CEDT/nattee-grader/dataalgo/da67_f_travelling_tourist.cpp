#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int N = 503;
int dp[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  vector<int> s(k); for(auto &x : s) cin >> x;

  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      dp[i][j] = INT_MAX;
    }
    dp[i][i] = 0;
  }

  for(int i=0; i<m; ++i) {
    int u, v, w; cin >> u >> v >> w; u--, v--;
    dp[u][v] = min(dp[u][v], w);
    dp[v][u] = min(dp[v][u], w);
  }

  for(int k=0; k<n; ++k) {
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        if(dp[i][k] == INT_MAX or dp[k][j] == INT_MAX) continue ;
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  vector<int> ord(k);
  iota(ord.begin(), ord.end(), 0);

  int res = INT_MAX;
  do {
    int r = 0, p = -1;
    for(auto &o : ord) {
      int u = s[o]; u--;
      if(p != -1) {
        r += dp[p][u];
      }
      p = u;
    }
    res = min(res, r);
  }while(next_permutation(ord.begin(), ord.end()));

  cout << res;
  return 0;
}

