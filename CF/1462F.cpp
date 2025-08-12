#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define ld long double

#define all(x) begin(x), end(x)
#define pb emplace_back

void solve() {
  int n; cin >> n;

  using pi = pair<int, int>;
  vector<int> a, b;
  vector<pi> v;
  for(int i=0; i<n; ++i) {
    int l, r; cin >> l >> r;
    v.pb(l, r); a.pb(l); b.pb(r);
  }

  sort(all(a));
  sort(all(b));
  int res = INT_MAX;
  for(auto [l, r] : v) {
    int it = upper_bound(all(a), r) - begin(a);
    it = n - it;
    int it2 = lower_bound(all(b), l) - begin(b);
    res = min(res, it+it2);
  }

  cout << res << ln;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T; cin >> T; while(T--) solve();
  return 0;
}
