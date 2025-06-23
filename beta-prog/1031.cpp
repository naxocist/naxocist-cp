#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e4 + 3;
vector<int> adj[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int k, n, m; cin >> k >> n >> m;

  while(m--) {
    int u, v; cin >> u >> v; adj[v].pb(u);
  }

  vector<int> mn(n + 1, 2e9);
  mn[1] = 0;
  for(int i=2; i<=n; ++i) {
    for(auto j : adj[i]) mn[i] = min(mn[i], mn[j] + 1);
  }

  for(int i=n; i>=1; --i) {
    if(mn[i] <= k) cout << i, exit(0);
  }
  
  return 0;
}
