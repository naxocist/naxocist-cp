#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back

const int N = 1e3 + 3;
vector<int> adj[N];
vector<int> c(N);

bool dfs(int u, int p) {
  if(c[u]) {
    return c[u] == 1;
  }

  c[u] = 1;
  for(int v : adj[u]) {
    if(v == p) continue ;
    if(dfs(v, u)) return true;
  }
  c[u] = 2;

  return false;
}

void solve() {
  int n, m; cin >> n >> m;
  for(int i=0; i<n; ++i) adj[i].clear(), c[i] = 0;
  while(m --) {
    int u, v; cin >> u >> v; adj[u].pb(v), adj[v].pb(u);
  }

  for(int i=0; i<n; ++i) {
    if(c[i]) continue ;
    if(dfs(i, -1)) {
      cout << "YES" << '\n';
      return ;
    }
  }
  cout << "NO" << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while(T --) solve();
  return 0;
}
