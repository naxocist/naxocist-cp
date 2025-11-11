#include <bits/stdc++.h>
#include <climits>
#include <queue>
using namespace std;


using ll = long long;
const int N = 1e3 + 3;
ll mat[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> mat[i][j];


  vector<ll> dist(n, LLONG_MAX);
  dist[0] = 0;

  priority_queue<pair<ll, int>> pq;
  pq.emplace(0, 0);

  while(pq.size()) {
    auto [d, u] = pq.top(); pq.pop();
    for(int v=0; v<n; ++v) {
      ll w = mat[u][v];
      if(w == -1 or u == v) continue ;
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.emplace(-dist[v], v);
      }
    }
  }

  ll mx = LONG_LONG_MIN;
  for(int i=1; i<n; ++i) {
    if(dist[i] == LONG_LONG_MAX) {
      mx = -1;
      break ;
    }
    mx = max(mx, dist[i]);
  }

  cout << mx;

  return 0;
}

