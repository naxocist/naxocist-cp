#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back

using pi = pair<int, int>;
const int N = 1e5 + 3;
vector<pi> adj[N];

int col[N];

void dfs(int u) {
  for(auto [v, w] : adj[u]) {
    if(!col[v]) col[v] = w ? col[u] : (col[u] == 1 ? 2 : 1), dfs(v);
    else {
      if(w and col[v] != col[u]) cout << "NO", exit(0);
      else if(!w and col[v] == col[u]) cout << "NO", exit(0);
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;

  vector<int> w(n); for(auto &x : w) cin >> x;

  vector<vector<int>> s(n);
  for(int i=0; i<m; ++i){
    int x; cin >> x;
    while(x--) {
      int k; cin >> k; k--;
      s[k].pb(i);
    }
  }


  for(int i=0; i<n; ++i) {
    vector<int> z = s[i];
    int u = z[0], v = z[1];
    // cout << u << ' ' << v << ' ' << w[i] << '\n';
    adj[u].pb(v, w[i]), adj[v].pb(u, w[i]);
  }

  for(int i=0; i<m; ++i) {
    if(col[i]) continue ;
    col[i] = 1; dfs(i);
  }

  // for(int i=0; i<m; ++i) cout << col[i] << ' '; cout << '\n';

  cout << "YES";
  return 0;
}
