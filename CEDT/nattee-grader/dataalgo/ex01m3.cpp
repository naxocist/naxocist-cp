#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;

  vector<ll> v(n); for(auto &x : v) cin >> x;

  while(q --) {
    ll p; cin >> p;
    ll l = -1, r = 2e14;
    while(l + 1 < r) {
      ll m = l + (r-l)/2;

      ll s = 0;
      for(auto &x : v) s += (m + x - 1)/x;
      if(s < p) l = m;
      else r = m;
    }

    cout << l << '\n';
  }
  return 0;
}
