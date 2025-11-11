#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 3;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, st; cin >> n >> m >> st;

  using T = tuple<int, int, int>;
  vector<T> edge;
  while(m --) {
    int u, v, w; cin >> u >> v >> w;
    edge.emplace_back(u, v, w);
  }

  vector<int> dist(n, INT_MAX);
  dist[st] = 0;

  bool neg_cycle = false;
  bool no = true;
  for(int i=0; i<n; ++i) {
    for(auto [u, v, w] : edge) {
      if(dist[u] == INT_MAX) continue ;
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        if(i == n-1) neg_cycle = true;
        no = false;
      }
    }
  }

  if(neg_cycle or no) cout << -1, exit(0);

  for(int i=0; i<n; ++i) cout << dist[i] << ' ';

  return 0;
}

