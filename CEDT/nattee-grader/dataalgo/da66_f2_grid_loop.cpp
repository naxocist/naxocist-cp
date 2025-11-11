#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
const int N = 1e3 + 3;
unsigned char ar[N][N];
int n, m;
bool deg2;
int sz;
int cycle, mx;
vector<char> vis;
vector<array<int, 2>> adj;

void dfs(int u) {
  deg2 = deg2 and adj[u][1] != -1;
  sz ++;
  vis[u] = 1;
  for(int k=0; k<2; ++k) {
    int v = adj[u][k];
    if(v == -1 or vis[v]) continue;
    dfs(v);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  vis.assign(n*m, 0);
  adj.assign(n*m, array<int,2>{-1,-1});
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
    int x; cin >> x;
    ar[i][j] = x;
  }

  int tr[] = {-1, 1, 0, 0};
  int tc[] = {0, 0, -1, 1};
  int to_check[7][2] = {
    {-1, -1},
    {2, 3},
    {0, 1},
    {0, 3},
    {1, 3},
    {2, 1},
    {2, 0}
  };

  for(int r=0; r<n; ++r) {
    for(int c=0; c<m; ++c) {
      int x = ar[r][c];
      for(int k=0; k<2; ++k) {
        int dx = to_check[x][k];
        int nr = r + tr[dx], nc = c + tc[dx];
        if(nr < 0 or nc < 0 or nr >= n or nc >= m) continue ;
        int y = ar[nr][nc];
        int dy1 = to_check[y][0], dy2 = to_check[y][1];
        int tar[] = {1, 0, 3, 2};
        if(dy1 == tar[dx] or dy2 == tar[dx]) {
          if(adj[r*m+c][0] == -1) adj[r*m+c][0] = nr*m+nc;
          else adj[r*m+c][1] = nr*m+nc;
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

