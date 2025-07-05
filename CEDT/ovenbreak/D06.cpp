#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  int ar[n][m];
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> ar[i][j];

  int r, c; cin >> r >> c; r--, c--;

  ll res = 0;
  for(int i=0; i<n; ++i) res += ar[i][c];
  for(int j=0; j<m; ++j) res += ar[r][j];
  res -= ar[r][c];
  cout << res;

  return 0;
}