#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<int> v(n); for(auto &x : v) cin >> x;

  while(q --) {
    int x; cin >> x;
    int l = -1 , r = n;
    while(l + 1 < r) {
      int m = l + (r-l)/2;
      if(v[m] <= x) l = m;
      else r = m;
    }

    cout << l << '\n';
  }
  return 0;
}
