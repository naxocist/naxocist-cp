#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  set<pair<int, int>> s;

  for(int i=0; i<k; ++i) {
    int r, c; cin >> r >> c; 
    s.emplace(r, c);
  }

  auto [ax, ay] = *s.begin();

  int q; cin >> q;
  while(q --) {
    int r, c; cin >> r >> c;

    auto it = s.upper_bound({r, c});
    if(it == s.end()) {
      ll to_first = 1ll*(ax-1)*m+(ay-1) + 1ll*(n-r)*m+(m-c) + 1;
      cout << to_first << '\n';
      continue ;
    }

    auto [x, y] = *it;
    ll res = 1ll*max(0, x-r-1)*m + (m-c) + y;
    if(x == r) res = y - c;
    cout << res << '\n';
  }

  return 0;
}

