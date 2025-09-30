#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

map<int, set<int>> adj;
int n, a, b;

vector<vector<int>> res;
vector<int> r;

void dfs(int u) {
  if(u == b) {
    res.pb(r);
    return ;
  }

  for(int v : adj[u]) {
    r.pb(v);
    dfs(v);
    r.pop_back();
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> a >> b;

  while(n--) {
    int u, v; cin >> u >> v;
    adj[u].insert(v);
  }

  r.pb(a);
  dfs(a);
  if(res.empty()) {
    cout << "no"; return 0;
  }

  // cout << "yes"; return 0;

  for(auto v : res) {
    for(int i=0; i<v.size(); ++i) {
      if(i) cout << " -> ";
      cout << v[i];
    }
    cout << '\n';
  }
  return 0;
}
