#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
const int N = 23;
using pi = pair<int, int>;
vector<pi> adj[N];
vector<bool> vis;
vector<int> lm(N);

bool dfs(int u, int s, int lim, int &x) {
  if(s > x or s + lim < x) return 0;
  if(s == x) return 1;

  vis[u] = 1;
  for (auto [v, w] : adj[u]) {
    if (vis[v]) continue;
    if(dfs(v, s+w, lim-lm[v], x)) return 1;
  }
  vis[u] = 0;

  return 0;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vis.resize(n);

  vector<int> q(8);
  for (auto &k : q) cin >> k;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].pb(v, w);
    adj[v].pb(u, w);
  }

  int limit = 0;
  for(int u=0; u<n; ++u) {
    for(auto [v, w] : adj[u]) lm[u] = max(lm[u], w);
    limit += lm[u];
  }

  for (auto &x : q) {
    bool ok = 0;

    for(int u=0; u<n; ++u) {
      fill(vis.begin(), vis.end(), 0);
      if(dfs(u, 0, limit-lm[u], x)) {
        ok = 1;
        break ;
      }
    }

    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
