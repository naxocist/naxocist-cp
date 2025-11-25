#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 2e3 + 3, M = 1e3 + 3, mod = 1e9 + 7;
int qs[N][N], C[M][M];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      char c; cin >> c;
      if(c == 'a') qs[i][j] ++;
      qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
    }
  }

  for(int i=0; i<M; ++i) {
    for(int j=0; j<M; ++j) {
      if(j > i) {
        C[i][j] = -1;
        continue ;
      }
      if(j == 0 or j == i) {
        C[i][j] = 1;
        continue ;
      }
      C[i][j] = C[i-1][j] + C[i-1][j-1];
      C[i][j] %= mod;
    }
  }

  int q; cin >> q;
  while(q --) {
    int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
    int s = qs[c][d] - qs[a-1][d] - qs[c][b-1] + qs[a-1][b-1];
    cout << C[s][k] << '\n';
  }
  return 0;
}
