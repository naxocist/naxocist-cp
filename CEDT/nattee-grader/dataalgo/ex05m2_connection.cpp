#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
vector<int> adj[N];
vector<bool> vis(N);


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  while(m --) {
    int u, v; cin >> u >> v;
    adj[u].emplace_back(v), adj[v].emplace_back(u);
  }

  int mx = 0;
  for(int i=0; i<n; ++i) {
    fill(vis.begin(), vis.end(), false);
    int cnt = 0;

    queue<pair<int, int>> q;
    q.emplace(i, k);
    while(q.size()) {
      auto [u, d] = q.front(); q.pop();
      if(vis[u]) continue ;
      vis[u] = 1;
      if(d >= 0) cnt ++;
      else continue;

      for(int &v : adj[u]) {
        q.emplace(v, d-1);
      }
    }

    mx = max(mx, cnt);
  }
  cout << mx;
  return 0;
}
