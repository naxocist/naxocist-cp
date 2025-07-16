#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back

using ll = long long;
using mll = map<ll, ll>;
const int N = 1e5 + 3;
vector<int> adj[N];
ll col[N], res[N], mx[N];

mll dfs(int u, int p) {

  mll cnt;
  cnt[col[u]] ++;
  mx[u] = 1;
  res[u] = col[u];

  for(auto v : adj[u]) {
    if(v == p) continue ;
    mll d = dfs(v, u);
    if(d.size() > cnt.size()) {
      swap(d, cnt);
      mx[u] = mx[v];
      res[u] = res[v];
    }

    for(auto [x, y] : d) {
      cnt[x] += y;
      if(cnt[x] > mx[u]) {
        mx[u] = cnt[x];
        res[u] = x;
      }else if(cnt[x] == mx[u]) {
        res[u] += x;
      }
    }
  }

  return cnt;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=1; i<=n; ++i) cin >> col[i];
  for(int i=1; i<n; ++i) {
    int u, v; cin >> u >> v; adj[u].pb(v); adj[v].pb(u);
  }

  dfs(1, 0);
  for(int i=1; i<=n; ++i) cout << res[i] << ' ';
  return 0;
}
