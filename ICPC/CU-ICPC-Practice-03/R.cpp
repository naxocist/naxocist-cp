#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 2e5 + 1;
vector<int> adj[N];

void solve() {
  int n; cin >> n;

  for(int i=1; i<=n; +++i) adj[i].clear();

  for(int i=0; i<n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
  }


}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
