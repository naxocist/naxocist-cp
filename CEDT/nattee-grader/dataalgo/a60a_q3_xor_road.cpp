#include <bits/stdc++.h>
#include <queue>
using namespace std;

using ll = unsigned long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> id(n); for(auto &x : id) cin >> x;


  priority_queue<pair<ll, int>> pq;
  pq.emplace(0, 0);
  vector<bool> vis(n);

  ll res = 0;
  int cnt = 0;
  while(pq.size()) {
    auto [d, u] = pq.top(); pq.pop();
    if(vis[u]) continue ;
    res += d;
    vis[u] = 1;
    cnt ++;
    if(cnt == n) break ;
    for(int v=0; v<n; ++v) {
      pq.emplace(id[u]^id[v], v);
    }
  }
  cout << res;
  return 0;
}
