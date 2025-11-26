#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 1e3 + 3;
vector<int> adj[N];
bool vis[N];

bool dfs(int u, int p) {
  vis[u] = 1;
  for(auto &v : adj[u]) {
    if(vis[v]) {
      if(v != p) return true;
    }else if(dfs(v, u)) return true;
  }
  return false;
}

void solve() {
  int n, m; cin >> n >> m;
  for(int i=0; i<n; ++i) adj[i].clear(), vis[i] = 0;
  while(m --) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }

  for(int i=0; i<n; ++i) {
    if(vis[i]) continue ;
    if(dfs(i, -1)) {
      cout << "YES\n"; 
      return ;
    }
  }

  cout << "NO\n";
  return ;
}
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t; cin >> t; while(t --) solve();
  return 0;
}
