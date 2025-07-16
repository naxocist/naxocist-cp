#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 503;
int ar[N][N], ar2[N][N];
bool ok[N][N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    string s; cin >> s;
    for(int j=1; j<=m; ++j) {
      char c = s[j-1];
      ok[i][j] = c == '.';

      ar[i][j] = ar[i-1][j] + ar[i][j-1] - ar[i-1][j-1];
      ar2[i][j] = ar2[i-1][j] + ar2[i][j-1] - ar2[i-1][j-1];
      if(ok[i][j]) {
        ar[i][j] += ok[i-1][j];
        ar2[i][j] += ok[i][j-1];
      }
    }
  }

  int q; cin >> q;
  while(q--) {
    int r, c, a, b; cin >> r >> c >> a >> b;
    int s = ar[a][b] - ar[r][b] - ar[a][c-1] + ar[r][c-1];
    s += ar2[a][b] - ar2[r-1][b] - ar2[a][c] + ar2[r-1][c];
    cout << s << '\n';
  }
  return 0;
}
