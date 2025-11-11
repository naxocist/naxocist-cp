#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> val(n*m);
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cin >> val[i*m+j];
    }
  }

  vector<int> dist(n*m, INT_MAX);
  dist[0] = 0;
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, 0);


  int t[] = {1, 0, -1, 0, 1};
  while(pq.size()) {
    auto [d, cr] = pq.top(); pq.pop();
    int r = cr/m, c = cr%m;
    for(int i=0; i<4; ++i) {
      int nr = r + t[i], nc = c + t[i + 1];
      if(nr < 0 or nr >= n or nc < 0 or nc >= m) continue ;
      int go = nr*m+nc;
      if(dist[cr] + val[go] < dist[go]) {
        dist[go] = dist[cr] + val[go];
        pq.emplace(-dist[go], go);
      }
    }
  }

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cout << dist[i*m+j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
