#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 2e5 + 3;
vector<int> adj[N];
int pos[N];

bool f(int u, int v) {
  return pos[u] < pos[v];
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  for(int i=1; i<n; ++i) {
    int u, v; cin >> u >> v; 
    adj[u].pb(v); adj[v].pb(u);
  }

  vector<int> t;
  for(int i=0; i<n; ++i) {
    int x; cin >> x;
    pos[x] = i; t.pb(x);
  }

  for(int i=1; i<=n; ++i) sort(all(adj[i]),f);


  vector<bool> vis(n + 1);
  queue<int> q;
  q.emplace(1);

  vector<int> r;
  while(q.size()) {
    int u = q.front(); q.pop();
    if(vis[u]) continue ;
    vis[u] = 1;
    r.pb(u);
    for(auto v : adj[u]) {
      q.emplace(v);
    }
  }

  if(r == t) cout << "Yes";
  else cout << "No";
  return 0;
}
