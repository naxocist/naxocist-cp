#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back


const int N = 1e5 + 3;
int val[N];
vector<int> adj[N];
multiset<int> s[N];

void dfs(int u, int p) {
  for(int v : adj[u]) {
    if(v == p) continue ;
    dfs(v, u);
    for(auto &x : s[v]) s[u].emplace(x);
    s[v].clear();
  }

  auto t = s[u].upper_bound(val[u]);
  if(t != s[u].end()) s[u].erase(t);
  s[u].emplace(val[u]);
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=0; i<n; ++i) cin >> val[i];
  for(int i=1; i<n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
  }

  dfs(0, 0);

  cout << n - (int)s[0].size();
  return 0;
}
