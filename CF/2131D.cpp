#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 2e5 + 3;
vector<int> adj[N];

void solve() {
  int n; cin >> n;

  for(int i=0; i<n; ++i) adj[i].clear();

  vector<int> in(n);
  for(int i=1; i<n; ++i) {
    int u, v; cin >> u >> v; u --, v --;
    adj[u].pb(v); adj[v].pb(u);
    in[v] ++; in[u] ++;
  }

  if(n <= 3) {
    cout << 0 << ln;
    return ;
  }

  int mx = 0;
  int leaf = 0;
  for(int i=0; i<n; ++i) {
    leaf += in[i] == 1;
    int m = 0;
    for(auto v : adj[i]) {
      m += in[v] == 1;
    }
    mx = max(mx, m);
  }

  cout << leaf - mx << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
