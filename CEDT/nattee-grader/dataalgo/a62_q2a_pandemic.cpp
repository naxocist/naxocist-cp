#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 3;
bool no[N][N];
bool virus[N][N];
using T = tuple<int, int, int>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, tt; cin >> n >> m >> tt;

  queue<T> q;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      int x; cin >> x;
      if(x == 0) continue ;
      if(x == 1) q.emplace(i, j, tt);
      if(x == 2) no[i][j] = 1;
    }
  }

  int res = 0;
  int go[] = {1, 0, -1, 0, 1};
  while(q.size()) {
    auto [r, c, t] = q.front(); q.pop();
    if(virus[r][c]) continue ;
    virus[r][c] = 1;
    res ++;

    if(t == 0) continue ;
    for(int i=0; i<4; ++i) {
      int nr = r + go[i], nc = c + go[i+1];
      if(nr < 0 or nc < 0 or nr >= n or nc >= m) continue ;
      if(virus[nr][nc] or no[nr][nc]) continue ;
      q.emplace(nr, nc, t-1);
    }
  }

  cout << res;
  return 0;
}

