#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

using pi = pair<int, int>;
const int N = 5e3 + 3;
vector<pi> adj[N];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  int t; cin >> t;
  vector<int> s(k); for(auto &x : s) cin >> x;

  while(m --) {
    int u, v, w; cin >> u >> v >> w;
    adj[v].pb(u, w);
  }

  vector<int> dist(n, INT_MAX);
  dist[t] = 0;
  priority_queue<pi> pq;
  pq.emplace(dist[t], t);
  while(pq.size()) {
    auto [d, u] = pq.top(); pq.pop();
    if(-d > dist[u]) continue ;
    for(auto &[v, w] : adj[u]) {
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.emplace(-dist[v], v);
      }
    }
  }

  int res, mn = INT_MAX;
  for(auto &x : s) {
    if(dist[x] < mn) mn = dist[x], res = x;
  }
  cout << mn;
  return 0;
}
