#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
const int N = 1e5 + 3;
vector<int> adj[N];
bool no[N];
int legs[N];

void dfs(int u, int p = -1) {
  if(adj[u].size() > 2) return ;
  no[u] = 1;
  for(int v : adj[u]) if(v != p) dfs(v, u);
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i=1; i<n; ++i) {
    int u, v; cin >> u >> v; adj[u].pb(v); adj[v].pb(u);
  }

  for(int u=1; u<=n; ++u) {
    if(adj[u].size() == 1) dfs(u);
  }

  for(int u=1; u<=n; ++u) {
    for(int v : adj[u]) {
      if(no[v]) legs[u]++;
    }
  }

  for(int u=1; u<=n; ++u) {
    if(no[u]) continue ;
    int cnt = 0;
    for(int v : adj[u]) cnt += adj[v].size()-min(legs[v],2) > 1 and !no[v];

    // cout << u << ' ' << cnt << endl;
    if(cnt > 2) cout << "No", exit(0);
  }

  cout << "Yes";
  return 0;
}
