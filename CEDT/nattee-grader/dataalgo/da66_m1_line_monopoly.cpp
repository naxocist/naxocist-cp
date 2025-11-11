#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int q; cin >> q;

  set<pair<int, int>> s;
  s.emplace(-1, -1);
  s.emplace(1e9 + 3, 1e9 + 3);

  int res = 0;
  while(q --) {
    int o; cin >> o;
    if(o == 1) {
      int l, r; cin >> l >> r; r ++;
      auto it = s.upper_bound({l, -1});
      auto prv = prev(it);
      if(prv->first <= l and l <= prv->second) {
        l = prv->first;
        r = max(r, prv->second);
        s.erase(prv);
      }

      while(it->first <= r) {
        r = max(r, it->second);
        it = s.erase(it);
      }
      s.emplace(l, r);
      res = (int)s.size() - 2;
    }else {
      cout << res << '\n';
    }
  }
  return 0;
}
