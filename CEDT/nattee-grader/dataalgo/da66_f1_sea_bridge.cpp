#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 3;
int a[N][N], b[N][N];
bool no[N][N];


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;

  queue<pair<int, int>> qa, qb;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      int x; cin >> x;
      if(x == 1) qa.emplace(i*m+j, 0);
      if(x == 2) qb.emplace(i*m+j, 0);
      if(x == 3) no[i][j] = 1;

      a[i][j] = b[i][j] = INT_MAX;
    }
  }

  int t[] = {1, 0, -1, 0, 1};
  while(qa.size()) {
    auto [x, d] = qa.front(); qa.pop();
    int r = x/m, c = x%m;
    if(d >= a[r][c] or no[r][c]) continue ;
    a[r][c] = d;
    for(int i=0; i<4; ++i) {
      int nr = r + t[i], nc = c + t[i + 1];
      if(nr < 0 or nc < 0 or nr >= n or nc >= m) continue ;
      qa.emplace(nr*m+nc, d+1);
    }
  }

  while(qb.size()) {
    auto [x, d] = qb.front(); qb.pop();
    int r = x/m, c = x%m;
    if(d >= b[r][c] or no[r][c]) continue ;
    b[r][c] = d;
    for(int i=0; i<4; ++i) {
      int nr = r + t[i], nc = c + t[i + 1];
      if(nr < 0 or nc < 0 or nr >= n or nc >= m) continue ;
      qb.emplace(nr*m+nc, d+1);
    }
  }

  int res = INT_MAX;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      if(no[i][j] or a[i][j] == INT_MAX or b[i][j] == INT_MAX) continue ;
      res = min(res, a[i][j] + b[i][j] + 1);
    }
  }
  cout << res;
  return 0;
}

