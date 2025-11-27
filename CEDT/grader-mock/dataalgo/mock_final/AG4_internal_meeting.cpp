#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
using ll = long long;
using pi = pair<ll, ll>;
const int N = 5e5 + 3;
vector<pair<ll, ll>> adj[N], adj2[N];
ll dist[N], dist2[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  s--;

  for (int i = 0; i < m; ++i) {
    int u, v, d, t;
    cin >> u >> v >> d >> t;
    u--, v--;
    if (t == 0) {
      adj[v].pb(u, d);
    } else {
      adj2[v].pb(u, d);
    }
  }
  vector<int> point(k);
  for (auto &x : point)
    cin >> x, x--;

  for (int i = 0; i < n; ++i)
    dist[i] = dist2[i] = INT_MAX;
  priority_queue<pi> pq;
  pq.emplace(0, s);
  dist[s] = 0;
  while (pq.size()) {
    auto [d, u] = pq.top();
    pq.pop();
    for (auto &[v, w] : adj[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.emplace(-dist[v], v);
      }
    }
  }

  dist2[s] = 0;
  pq.emplace(0, s);
  while (pq.size()) {
    auto [d, u] = pq.top();
    pq.pop();
    for (auto &[v, w] : adj2[u]) {
      if (dist2[u] + w < dist2[v]) {
        dist2[v] = dist2[u] + w;
        pq.emplace(-dist2[v], v);
      }
    }
  }

  map<ll, vector<string>> res;
  for (int i = 0; i < (1 << k); ++i) {
    string s;
    ll r = 0;
    for (int j = 0; j < k; ++j) {
      if (i & (1 << j)) {
        s += '1';
        r += dist2[point[j]];
      } else {
        s += '0';
        r += dist[point[j]];
      }
    }
    res[r].pb(s);
  }

  auto t = *res.begin();
  cout << t.first << '\n';
  for (auto &x : t.second)
    cout << x << '\n';
  return 0;
}
