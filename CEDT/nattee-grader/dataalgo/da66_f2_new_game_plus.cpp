#include <bits/stdc++.h>
using namespace std;
const int N = 503;
const int mod = 1e8 + 7;
bool no[N][N];
int x[N][N], y[N][N], z[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      cin >> no[i][j];
      if(!no[i][j]) x[i][j] = y[i][j] = z[i][j] = 1;
    }
  }

  int res = 0;
  for(int j=2; j<=m; ++j) {
    for(int i=1; i<=n; ++i) {
      if(no[i][j]) continue ;
      x[i][j] = y[i][j-1] + z[i-1][j-1]; x[i][j] %= mod;
      y[i][j] = x[i+1][j-1] + z[i-1][j-1]; y[i][j] %= mod;
      z[i][j] = x[i+1][j-1] + y[i][j-1]; z[i][j] %= mod;
      if(j == m) res += x[i+1][j-1] + y[i][j-1] + z[i-1][j-1], res %= mod;
    }
  }

  cout << res;
  return 0;
}
