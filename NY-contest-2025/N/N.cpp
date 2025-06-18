#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 3, LOG = 20;
vector<pair<int, ll>> adj[N];
ll dt[N];
int up[N][LOG], dep[N], dsu[N];

int par(int u) { return dsu[u] == u ? u : dsu[u] = par(dsu[u]); }

void dfs(int u, int p) {
  up[u][0] = p;
  for (int i = 1; i < LOG; ++i)
    up[u][i] = up[up[u][i - 1]][i - 1];

  for (auto [v, w] : adj[u]) {
    if (v == p)
      continue;
    dep[v] = dep[u] + 1;
    dt[v] = dt[u] + w;
    dfs(v, u);
  }
}

int lca(int a, int b) {
  if (dep[a] < dep[b])
    swap(a, b);

  int t = dep[a] - dep[b];
  for (int i = 0; i < LOG; ++i) if (t & (1 << i)) a = up[a][i];

  if (a == b)
    return a;

  for (int i = LOG - 1; i >= 0; --i) {
    if (up[a][i] != up[b][i]) {
      a = up[a][i], b = up[b][i];
    }
  }
  return up[a][0];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; ++i)
    dsu[i] = i;

  vector<tuple<ll, int, int>> edge;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.emplace_back(w, u, v);
  }

  sort(edge.begin(), edge.end());
  for (auto [w, u, v] : edge) {
    int uu = par(u), vv = par(v);
    if (uu == vv)
      continue;
    adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
    dsu[uu] = vv;
  }

  dfs(1, 1);

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << dt[a] + dt[b] - 2 * dt[lca(a, b)] << '\n';
  }
  return 0;
}
