#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define pb emplace_back
const int N = 703;
vector<pair<int, int>> adj[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, c; cin >> n >> c;
  adj[1].pb(2, c); adj[2].pb(1, c);
  for(int u=3; u<=n; ++u) {
    int k; cin >> k;
    while(k --) {
      int v, p; cin >> v >> p;
      adj[u].pb(v, p); adj[v].pb(u, p);
    }

    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);
    while(pq.size()) {
      auto [d, u] = pq.top(); pq.pop();
      for(auto &[v, w] : adj[u]) {
        if(dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.emplace(-dist[v], v);
        }
      }
    }
    cout << dist[2] << ' ';
  }
  return 0;
}

