#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int n, m;
int ar[N][N];
bool vis[N*N];
bool deg2;
int sz;
int cycle, mx;
vector<int> adj[N*N];

bool in(int r, int c) {
  return r >= 0 and c >= 0 and r < n and c < m;
}

void dfs(int u) {
  deg2 = deg2 and (int)adj[u].size() == 2;
  sz ++;
  vis[u] = 1;
  for(int v : adj[u]) {
    if(vis[v]) continue ;
    dfs(v);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> ar[i][j];

  // top-0 down-1 left-2 right-3
  int tr[] = {-1, 1, 0, 0};
  int tc[] = {0, 0, -1, 1};
  int to_check[7][2] = {
    {-1, -1},
    {2, 3}, // left right
    {0, 1}, // top down
    {0, 3}, // top right
    {1, 3}, // down right
    {2, 1}, // left down
    {2, 0} // top left
  };

  for(int r=0; r<n; ++r) {
    for(int c=0; c<m; ++c) {
      int x = ar[r][c];
      for(int k=0; k<2; ++k) {
        int dx = to_check[x][k];
        int nr = r + tr[dx], nc = c + tc[dx];
        if(!in(nr, nc)) continue ;
        int y = ar[nr][nc];
        int dy1 = to_check[y][0], dy2 = to_check[y][1];
        int tar[] = {1, 0, 3, 2}; // top <-> down, left <-> right
        if(dy1 == tar[dx] or dy2 == tar[dx]) {
          adj[r*m+c].emplace_back(nr*m+nc);
        }
      }
    }
  }

  for(int i=0; i<n*m; ++i) {
    if(vis[i]) continue ;
    deg2 = true;
    sz = 0;
    dfs(i);
    if(deg2) {
      cycle ++;
      mx = max(mx, sz);
    }
  }

  cout << cycle << " " << mx;
  return 0;
}

