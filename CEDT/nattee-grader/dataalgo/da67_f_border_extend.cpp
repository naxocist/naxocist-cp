#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int ar[N][N], d[N][N];

int main() {
  int n, m, k; cin >> n >> m >> k;

  using pii = pair<int, int>;
  queue<pii> q;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cin >> ar[i][j];
      d[i][j] = 2e9;
      if(ar[i][j]) {
        q.emplace(i, j);
        d[i][j] = 0;
      }
    }
  }

  int t[] = {1, 0, -1, 0, 1};
  while(q.size()) {
    auto [r, c] = q.front(); q.pop();

    for(int i=0; i<4; ++i) {
      int nr = r+t[i], nc = c+t[i+1];
      if(nr < 0 or nc < 0 or nr >= n or nc >= m) continue ;
      if(d[r][c] + 1 >= d[nr][nc]) continue ;
      d[nr][nc] = d[r][c] + 1;
      q.emplace(nr, nc);
    }
  }

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      if(ar[i][j]) cout << 1;
      else {
        if(d[i][j] <= k) cout << 2;
        else cout << 0;
      }
      cout << ' ';
    }
    cout << '\n';
  }
  return 0;
}
