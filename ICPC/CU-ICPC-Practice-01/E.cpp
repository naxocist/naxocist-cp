#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 1;
vector<int> adj[N];

int dfs(int u, int p) {
  int mx = 0;
  for(auto v : adj[u]) {
    if(v == p) continue ;
    mx = max(mx, dfs(v, u));
  }

  return mx + 1;
}

int main() {
  int n; cin >> n;
  for(int i=1; i<=n; ++i) {
    int p; cin >> p;
    if(p == -1) continue ;
    adj[p].emplace_back(i);
  }

  int mx = 0;
  for(int i=1; i<=n; ++i) {
    mx = max(mx, dfs(i, -1));
  }
  cout << mx;

  return 0;
}
