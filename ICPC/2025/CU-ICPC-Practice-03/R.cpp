#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 2e5 + 1;
set<int> adj[N];

void solve() {
  ll n; cin >> n;

  for(int i=1; i<=n; ++i) adj[i].clear();

  for(int i=0; i<n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].insert(v), adj[v].insert(u);
  }

  queue<int> q;
  for(int i=1; i<=n; ++i) {
    if(adj[i].size() == 1) q.emplace(i);
  }


  vector<ll> v(n + 1, 1);
  while(q.size()) {
    int u = q.front(); q.pop();
    int p = *(adj[u].begin());
    v[p] += v[u];
    v[u]=0;
    adj[p].erase(u);
    if(adj[p].size() == 1) q.emplace(p);
  }

  ll res = 0;
  for(int i=1; i<=n; ++i) {
    res += v[i]*(v[i]-1)/2;
    res += v[i]*(n-v[i]);
  }
  cout << res << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
