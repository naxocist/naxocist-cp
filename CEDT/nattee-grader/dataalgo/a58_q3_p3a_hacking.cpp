#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
const int N = 1e5 + 3;
vector<int> adj[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;

  vector<int> first(k); for(auto &x : first) cin >> x;
  vector<int> val(n); for(auto &x : val) cin >> x;

  while(m --) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }

  queue<pair<int, int>> q;
  for(auto &u : first) {
    q.emplace(u, val[u]);
  }

  vector<int> mn(n, INT_MAX);
  while(q.size()) {
    auto [u, d] = q.front(); q.pop();
    if(d >= mn[u]) continue ;
    mn[u] = d;
    for(int &v : adj[u]) {
      q.emplace(v, d + val[v]);
    }
  }

  cout << *max_element(mn.begin(), mn.end());
  return 0;
}

