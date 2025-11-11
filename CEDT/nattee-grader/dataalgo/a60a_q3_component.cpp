#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back

const int N = 1e4 + 3;
vector<int> adj[N];
bitset<N> vis;

void dfs(int u, int p) {
  if(vis[u]) return ;
  vis[u] = 1;
  for(int &v : adj[u]) {
    if(v == p) continue ;
    dfs(v, u);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  while(m --) {
    int u, v; cin >> u >> v; u --, v--;
    adj[u].pb(v); adj[v].pb(u);
  }

  int res = 0;
  for(int i=0; i<n; ++i) {
    if(vis[i]) continue;
    res ++;
    dfs(i, -1);
  }
  cout << res;
  return 0;
}

