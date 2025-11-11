#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
const int N = 1e5 + 3;
vector<int> adj[N];
vector<int> dist;

void dfs(int u, int p) {
  if(dist[u] != -1) {
    cout << dist[p] - dist[u] + 1;
    exit(0);
  }

  if(p != -1) dist[u] = dist[p] + 1;
  for(int &v : adj[u]) {
    if(v == p) continue ;
    dfs(v, u);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  dist.resize(n, -1);
  for(int i=0; i<n; ++i) {
    int u, v; cin >> u >> v; adj[u].pb(v); adj[v].pb(u);
  }
  dfs(0, -1);
  return 0;
}
