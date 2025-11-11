#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
const int N = 53;
vector<int> adj[N];
vector<int> color(N);
int n, m, k;

bool f(int u) {
  if(u == n) return 1;
  for(int i=1; i<=m; ++i) {
    bool chk = 1;
    for(int &v : adj[u]) chk = chk and i != color[v];
    if(!chk) continue ;
    color[u] = i;
    if(f(u+1)) return 1;
    color[u] = 0;
  }

  return 0;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  while(k --) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  int l = 0, r = n + 1;
  while(l + 1 < r) {
    m = l + (r-l)/2;
    if(f(0)) r = m;
    else l = m;
  }

  cout << r;
  return 0;
}
