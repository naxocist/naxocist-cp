#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N];
vector<pair<int, int>> edge;
vector<bool> vis(N);
vector<int> nodes;
int sz;

void dfs(int u) {
  nodes.emplace_back(u);
  vis[u] = 1;
  for(int &v : adj[u]) {
    if(vis[v]) continue ;
    dfs(v);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m; cin >> n >> m;

  vector<int> deg(n);
  while(m --) {
    int u, v; cin >> u >> v;
    adj[u].emplace_back(v); adj[v].emplace_back(u);
    deg[u] ++, deg[v] ++;
  }

  int res = 0;
  for(int u=0; u<n; ++u) {
    if(vis[u]) continue ;
    nodes.clear();
    dfs(u);

    int sz = nodes.size();
    map<int, int> cnt;
    for(auto &x : nodes) cnt[deg[x]] ++;

    res += (cnt[1] == 2 and cnt[2] == sz - 2) or sz == 1;
  }

  cout << res;
  return 0;
}

