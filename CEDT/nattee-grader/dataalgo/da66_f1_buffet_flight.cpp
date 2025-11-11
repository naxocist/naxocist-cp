#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int N = 2e3 + 3;
vector<int> adj[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> ci(n), co(n);
  for(auto &x : ci) cin >> x;
  for(auto &x : co) cin >> x;

  while(m --) {
    int u, v; cin >> u >> v;
    adj[u].emplace_back(v);
  }

  priority_queue<pair<int, int>> pq;
  pq.emplace(0, 0);
  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  while(pq.size()) {
    auto [d, u] = pq.top(); pq.pop();

    for(int &v : adj[u]) {
      int w = co[u] + ci[v];
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.emplace(-dist[v], v);
      }
    }
  }

  replace(dist.begin(), dist.end(), INT_MAX, -1);
  for(int i=0; i<n; ++i) cout << dist[i] << ' ';
  return 0;
}

