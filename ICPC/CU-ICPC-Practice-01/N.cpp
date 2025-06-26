#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
using pi = pair<int, int>;

const int N = 1e5 + 3;
vector<int> adj[N];
int low[N], in[N], cnt, cut;
bool vis[N];

void dfs(int u, int p) {
  low[u] = in[u] = ++cnt;
  vis[u] = 1;
  for(auto v : adj[u]) {
    if(v == p) continue ;
    if(!vis[v]) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      cut += in[u] < low[v];
    }else {
      low[u] = min(low[u], low[v]);
    }
  }
}

set<pi> s;
void f(int u, int p) {
  vis[u] = 1;
  // cout << u << '\n';
  for(auto v : adj[u]) {
    if(v == p) continue ; 
    int x=min(u,v), y=max(u,v);
    if(s.find(pi(x,y)) == s.end()) cout << u << ' ' << v << '\n';
    s.emplace(pi(x, y));
    if(!vis[v]) f(v, u);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  for(int i=0; i<m; ++i) {
    int u, v; cin >> u >> v; adj[u].pb(v), adj[v].pb(u);
  }

  dfs(1,0);
  if(cut) cout << 0, exit(0);
  memset(vis, 0, sizeof vis);
  f(1,0);
  return 0;
}
