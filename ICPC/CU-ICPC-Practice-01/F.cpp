#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
  int n; ll h; cin >> n >> h;
  vector<ll> v(n); for(auto &x : v) cin >> x;
  ll l = -1, r = h + 1;
  while(l + 1 < r) {
    ll m = l + (r-l)/2;
    ll res = 0;
    for(int i=0; i<n-1; ++i) {
      res += min(v[i + 1], v[i] + m) - v[i];
    }
    res += m;

    if(res >= h) r = m;
    else l = m;
  }

  cout << r << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t; cin >> t; while(t--) solve();
  return 0;
}
