#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
using ll = long long;
using pi = pair<int, ll>;

const int N = 1e5 + 3;
const ll INF = LLONG_MAX;
vector<pi> adj[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;

  for(int i=0; i<m; ++i) {
    int u, v, w; cin >> u >> v >> w; adj[u].pb(v, w); adj[v].pb(u, w);
  }

  priority_queue<pi, vector<pi>, greater<pi>> pq;
  vector<ll> dist(n + 1, INF);
  vector<int> par(n + 1, -1);
  dist[1] = 0;
  pq.emplace(0, 1);
  while(pq.size()) {
    auto [d, u] = pq.top(); pq.pop();
    if(dist[u] < d) continue ;
    for(auto [v, w] : adj[u]) {
      if(dist[u] + w < dist[v]) {
        par[v] = u;
        dist[v] = dist[u] + w;
        pq.emplace(dist[v], v);
      }
    }
  }

  if(dist[n] == INF) cout << -1;
  else {
    stack<int> st;
    int p = n;
    while(p != -1) {
      st.emplace(p);
      p = par[p];
    }
    while(st.size()) cout << st.top() << ' ', st.pop();
  }
  return 0;
}
