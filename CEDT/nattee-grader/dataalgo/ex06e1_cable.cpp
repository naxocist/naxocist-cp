#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
const int N = 1e3 + 3;
int dsu[N];

int par(int u) {
  return (dsu[u] == u ? u : dsu[u] = par(dsu[u]));
}

void un(int u, int v) {
  u = par(u), v = par(v);
  if(u == v) return ;
  dsu[u] = v;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  iota(dsu, dsu+n, 0);

  using T = tuple<int, int, int>;
  vector<T> edge;
  for(int i=0; i<n-1; ++i) {
    for(int j=i+1; j<n; ++j) {
      int w; cin >> w; edge.pb(w, i, j);
    }
  }

  int res = 0;
  sort(edge.begin(), edge.end());
  for(auto [w, u, v] : edge) {
    if(par(u) == par(v)) continue ;
    un(u, v);
    res += w;
  }
  cout << res;

  return 0;
}

