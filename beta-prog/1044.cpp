#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 3;
int a[N][N], b[N][N];
int ar[N], ac[N], br[N], bc[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;

  int s = 0;
  for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) cin >> a[i][j], s += a[i][j];
  for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) cin >> b[i][j];

  for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) ar[i] += a[i][j];
  for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) ac[i] += a[j][i];
  for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) br[i] += b[i][j];
  for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) bc[i] += b[j][i];

  int mx = 0;
  for(int i=1; i<=n; ++i) mx = max(mx, s-ar[i]+br[i-1]+br[i+1]);
  for(int j=1; j<=m; ++j) mx = max(mx, s-ac[j]+bc[j-1]+bc[j+1]);

  cout << mx;
  return 0;
}
