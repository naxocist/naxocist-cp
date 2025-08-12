#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 2e5 + 3;
set<int> adj[N];

void solve() {
  int n; cin >> n;

  for(int i=0; i<n; ++i) adj[i].clear();

  for(int i=0; i<n; ++i) {
    int u, v; cin >> u >> v; u--, v--;
    adj[u].insert(v); adj[v].insert(u);
  }

  queue<int> q;
  for(int i=0; i<n; ++i) {
    if(adj[i].size() == 1) q.emplace(i);
  }

  vector<ll> cnt(n, 1);
  while(q.size()) {
    int u = q.front(); q.pop();

    int v = *adj[u].begin();
    adj[v].erase(u);
    cnt[v] += cnt[u];
    cnt[u] = 0;
    if(adj[v].size() == 1) q.emplace(v);
  }

  ll res = 0;
  for(int i=0; i<n; ++i) {
    res += cnt[i]*(n-cnt[i]);
    res += cnt[i]*(cnt[i]-1)/2;
  }

  cout << res << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
