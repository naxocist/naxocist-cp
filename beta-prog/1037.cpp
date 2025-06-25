#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

using pi = pair<int, int>;
const int N = 53, INF = 2e9;
char ar[N][N];
int d[N][N], w[N][N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m; cin >> n >> m;

  queue<pi> q;
  int x, y;

  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) d[i][j]=w[i][j]=INF;

  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
    char c; cin >> c; ar[i][j] = c;
    if(c == '*') q.emplace(i, j), d[i][j] = 0;
    if(c == 'S') x = i, y = j;
  }

  auto ok = [&](int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < m and ar[x][y] != 'X';
  };

  int t[] = {1, 0, -1, 0, 1};
  while(q.size()) {
    auto [r, c] = q.front(); q.pop();
    for(int i=0; i<4; ++i) {
      int nr = r + t[i], nc = c + t[i + 1];
      if(!ok(nr, nc) or ar[nr][nc] == 'D' or d[r][c]+1>=d[nr][nc]) continue ;
      d[nr][nc]=d[r][c]+1;
      q.emplace(nr, nc);
    }
  }

  q.emplace(x, y);
  w[x][y] = 0;
  while(q.size()) {
    auto [r, c] = q.front(); q.pop();

    if(ar[r][c] == 'D') {
      cout << w[r][c];
      return 0;
    }

    for(int i=0; i<4; ++i) {
      int nr = r + t[i], nc = c + t[i + 1];
      if(!ok(nr, nc) or w[r][c]+1>=w[nr][nc]) continue ;
      if(ar[nr][nc]!='D' and w[r][c]+1>=d[nr][nc]) continue ;
      w[nr][nc]=w[r][c]+1;
      q.emplace(nr, nc);
    }
  }

  cout << "KAKTUS";
  return 0;
}
