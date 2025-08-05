#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back


void solve() {
  int n, x; cin >> n >> x;
  vector<ll> v(n); for(auto &x : v) cin >> x;

  ll l = -1, r = 2e17;
  while(l + 1 < r) {
    ll m = l + (r-l)/2;
    bool ok = 1;

    ll s = 0;
    for(auto t : v) {
      s += max(m-t, 0ll);
      if(s > x) {
        ok = 0; break ;
      }
    }

    if(ok) l = m;
    else r = m;
  }

  cout << l << '\n';
}
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
